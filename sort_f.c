#include "util.h"
#include <stdlib.h>

static void merge_f(int *A, int *L, int n1, int *R, int n2) {
    int *endL = L + n1, *endR = R + n2, *pA = A;
    while (L < endL && R < endR)
        *pA++ = (*L <= *R) ? *L++ : *R++;
    while (L < endL) *pA++ = *L++;
    while (R < endR) *pA++ = *R++;
}

// internal recursive function
static void sort_f_recursive(int *A, int n, int *temp) {
    if (n <= 16) {
        isort(A, n);
        return;
    }

    int mid = n / 2;
    copy(temp, A, mid);

    sort_f_recursive(temp, mid, A);
    sort_f_recursive(A + mid, n - mid, A);

    merge_f(A, temp, mid, A + mid, n - mid);
}

// public wrapper
void sort_f(int *A, int n) {
    int *temp = malloc(n / 2 * sizeof(int));
    sort_f_recursive(A, n, temp);
    free(temp);
}
