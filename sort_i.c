#include "util.h"
#include <stdlib.h>

static inline void merge_i(int *A, int *L, int n1, int *R, int n2) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
        A[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1)
        A[k++] = L[i++];
    while (j < n2)
        A[k++] = R[j++];
}

void sort_i(int *A, int n) {
    if (n <= 1) return;

    int mid = n / 2;
    int *L = malloc(mid * sizeof(int));
    int *R = malloc((n - mid) * sizeof(int));

    copy(L, A, mid);
    copy(R, A + mid, n - mid);

    sort_i(L, mid);
    sort_i(R, n - mid);
    merge_i(A, L, mid, R, n - mid);

    free(L);
    free(R);
}
