#include "util.h"
#include <stdlib.h>

static inline void merge_p(int *A, int *L, int n1, int *R, int n2) {
    int *endL = L + n1, *endR = R + n2, *pA = A;
    while (L < endL && R < endR)
        *pA++ = (*L <= *R) ? *L++ : *R++;
    while (L < endL) *pA++ = *L++;
    while (R < endR) *pA++ = *R++;
}

void sort_p(int *A, int n) {
    if (n <= 1) return;

    int mid = n / 2;
    int *L = malloc(mid * sizeof(int));
    int *R = malloc((n - mid) * sizeof(int));

    copy(L, A, mid);
    copy(R, A + mid, n - mid);

    sort_p(L, mid);
    sort_p(R, n - mid);
    merge_p(A, L, mid, R, n - mid);

    free(L);
    free(R);
}
