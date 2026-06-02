#include "profiler.h"

int fact(int n) {
    PROFILE
    if (n <= 1) {
        return 1;
    }
    int res = n * fact(n - 1);
    return res;
}

int main(void) {
    PROFILE
    fact(10);
    return 0;
}