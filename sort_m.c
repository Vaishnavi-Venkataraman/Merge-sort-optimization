#include "util.h"
#include <stdlib.h>

static inline void merge_m(int *A, int *L, int n1, int *R, int n2) {
    int *endL = L + n1, *endR = R + n2, *pA = A;
    while (L < endL && R < endR)
        *pA++ = (*L <= *R) ? *L++ : *R++;
    while (L < endL) *pA++ = *L++;
    while (R < endR) *pA++ = *R++;
}

void sort_m(int *A, int n) {
    if (n <= 16) {
        isort(A, n);
        return;
    }

    int mid = n / 2;
    int *L = malloc(mid * sizeof(int));
    copy(L, A, mid);

    sort_m(L, mid);
    sort_m(A + mid, n - mid);
    merge_m(A, L, mid, A + mid, n - mid);

    free(L);
}
