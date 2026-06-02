#ifndef PROFILE_H
#define PROFILE_H

#include <stdio.h>
#include <time.h>

static inline void _profile_log(const char *name) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    double t = ts.tv_sec + ts.tv_nsec * 1e-9;
    FILE *fp = fopen("profile.log", "a");
    if (fp) {
        fprintf(fp, "%s -- time : %.6fs\n", name, t);
        fclose(fp);
    }
}

#define PROFILE _profile_log(__func__);

#define return \
    _profile_log("END"); \
    return

#endif