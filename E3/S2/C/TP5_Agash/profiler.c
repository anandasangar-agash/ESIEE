#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char   name[128];
    double t_start;
    double t_end;
    double duration;
    struct Node *child;
    struct Node *sibling;
} Node;

typedef struct Summary {
    char   name[128];
    int    calls;
    double total_time;
    struct Summary *next;
} Summary;

typedef struct LogEntry {
    char   name[128];
    double timestamp;
} LogEntry;

LogEntry *read_log(const char *filename, int *count) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Impossible d'ouvrir '%s'\n", filename);
        return NULL;
    }

    int capacity = 256;
    LogEntry *entries = malloc(capacity * sizeof(LogEntry));
    *count = 0;

    char name[128];
    double t;

    while (fscanf(fp, "%127s -- time : %lfs", name, &t) == 2) {
        if (*count >= capacity) {
            capacity *= 2;
            entries = realloc(entries, capacity * sizeof(LogEntry));
        }
        strncpy(entries[*count].name, name, 127);
        entries[*count].timestamp = t;
        (*count)++;
    }
    fclose(fp);
    return entries;
}

Node *build_tree(LogEntry *entries, int count) {
    if (count == 0) return NULL;

    Node **stack = malloc(count * sizeof(Node *));
    int   top    = 0;   

    Node *root = NULL;

    for (int i = 0; i < count; i++) {
        LogEntry *e = &entries[i];

        if (strcmp(e->name, "END") != 0) {
            Node *n = calloc(1, sizeof(Node));
            strncpy(n->name, e->name, 127);
            n->t_start = e->timestamp;

            if (top == 0) {
                root = n;
            } else {
                Node *parent = stack[top - 1];
                if (parent->child == NULL) {
                    parent->child = n;
                } else {
                    Node *sib = parent->child;
                    while (sib->sibling) sib = sib->sibling;
                    sib->sibling = n;
                }
            }
            stack[top++] = n;

        } else {
            if (top > 0) {
                Node *n = stack[--top];
                n->t_end   = e->timestamp;
                n->duration = n->t_end - n->t_start;
            }
        }
    }

    free(stack);
    return root;
}

void summary_add(Summary **head, const char *name, double duration) {
    Summary *s = *head;
    while (s) {
        if (strcmp(s->name, name) == 0) {
            s->calls++;
            s->total_time += duration;
            return;
        }
        s = s->next;
    }

    Summary *ns = calloc(1, sizeof(Summary));
    strncpy(ns->name, name, 127);
    ns->calls      = 1;
    ns->total_time = duration;
    ns->next       = *head;
    *head          = ns;
}

void fill_summary(Node *node, Summary **head) {
    if (!node) return;
    summary_add(head, node->name, node->duration);
    fill_summary(node->child,   head);
    fill_summary(node->sibling, head);
}

void sort_summary(Summary **head) {
    if (!*head) return;
    int swapped;
    do {
        swapped = 0;
        Summary **pp = head;
        while ((*pp)->next) {
            Summary *a = *pp;
            Summary *b = a->next;
            if (a->total_time < b->total_time) {
                a->next = b->next;
                b->next = a;
                *pp     = b;
                swapped = 1;
            }
            pp = &(*pp)->next;
        }
    } while (swapped);
}

void print_summary(Summary *head) {
    printf("\n");
    printf("%-30s %8s %15s %15s\n",
           "Fonction", "Appels", "Temps total (s)", "Temps/appel (s)");
    printf("%-30s %8s %15s %15s\n",
           "--------", "------", "---------------", "---------------");

    for (Summary *s = head; s; s = s->next) {
        double avg = (s->calls > 0) ? s->total_time / s->calls : 0.0;
        printf("%-30s %8d %15.6f %15.6f\n",
               s->name, s->calls, s->total_time, avg);
    }
    printf("\n");
}

void print_tree(Node *node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("[%s] %.6fs\n", node->name, node->duration);
    print_tree(node->child,        depth + 1);
    print_tree(node->sibling,      depth);
}

void free_tree(Node *node) {
    if (!node) return;
    free_tree(node->child);
    free_tree(node->sibling);
    free(node);
}

void free_summary(Summary *head) {
    while (head) {
        Summary *next = head->next;
        free(head);
        head = next;
    }
}

int main(int argc, char *argv[]) {
    const char *logfile = (argc >= 2) ? argv[1] : "profile.log";

    printf("=== Profileur C — lecture de '%s' ===\n", logfile);

    int count = 0;
    LogEntry *entries = read_log(logfile, &count);
    if (!entries || count == 0) {
        fprintf(stderr, "Log vide ou illisible.\n");
        return 1;
    }
    printf("%d entrées lues.\n", count);

    Node *root = build_tree(entries, count);
    free(entries);

    if (!root) {
        fprintf(stderr, "Arbre vide — log mal formé ?\n");
        return 1;
    }

    printf("\n--- Arbre des appels ---\n");
    print_tree(root, 0);

    Summary *summary = NULL;
    fill_summary(root, &summary);
    sort_summary(&summary);

    printf("--- Tableau récapitulatif ---");
    print_summary(summary);

    free_tree(root);
    free_summary(summary);

    return 0;
}