#include <stdio.h>
#include <time.h>

#define PROFILE \
    struct timespec ts; \
    clock_gettime(CLOCK_REALTIME, &ts); \
    double t = ts.tv_sec + ts.tv_nsec * 1e-9; \
    FILE *fp = fopen("profile.log", "a"); \
    fprintf(fp, "%s -- time : %fs\n", __FUNCTION__, t); \
    fclose(fp);

#define return(x) do { \
    struct timespec ts; \
    clock_gettime(CLOCK_REALTIME, &ts); \
    double t = ts.tv_sec + ts.tv_nsec * 1e-9; \
    FILE *fp = fopen("profile.log", "a"); \
    fprintf(fp, "END -- time : %fs\n", t); \
    fclose(fp); \
    return (x); \
} while(0)

int f(int n) {
    PROFILE
    if (n <= 1) {
        return 1;
    }
    int tmp = f(n - 1);
    int res = n * tmp;
    return res;
}

int main() {
    PROFILE
    f(3);
    return 0;
}