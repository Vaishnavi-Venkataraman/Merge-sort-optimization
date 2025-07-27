#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FUNCS 10

void sort_a(int *A, int n);
void sort_i(int *A, int n);
void sort_p(int *A, int n);
void sort_c(int *A, int n);
void sort_m(int *A, int n);
void sort_f(int *A, int n);

typedef void (*sortFunc)(int *, int);

sortFunc funcs[MAX_FUNCS];
const char *func_names[MAX_FUNCS];
int func_count = 0;

void testFunc(sortFunc f, const char *name) {
    funcs[func_count] = f;
    func_names[func_count] = name;
    func_count++;
}

int cmp(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

void benchmark(int n, int trials) {
    int *A = malloc(n * sizeof(int));
    int *B = malloc(n * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < func_count; i++) {
        double total = 0.0;
        for (int t = 0; t < trials; t++) {
            for (int j = 0; j < n; j++)
                A[j] = rand();
            memcpy(B, A, n * sizeof(int));

            clock_t start = clock();
            funcs[i](B, n);
            clock_t end = clock();

            total += (double)(end - start) / CLOCKS_PER_SEC;

            qsort(A, n, sizeof(int), cmp);
            for (int j = 0; j < n; j++) {
                if (A[j] != B[j]) {
                    printf("Error in %s\n", func_names[i]);
                    exit(1);
                }
            }
        }
        printf("%s: %f s\n", func_names[i], total / trials);
    }
    free(A);
    free(B);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <n> <trials>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    int trials = atoi(argv[2]);

    // Detect which executable we are
    char *progname = strrchr(argv[0], '/');
    progname = (progname) ? progname + 1 : argv[0];

    if (strcmp(progname, "sort_a") == 0) {
        testFunc(sort_a, "sort_a");
    } else if (strcmp(progname, "sort_i") == 0) {
        testFunc(sort_i, "sort_i");
    } else if (strcmp(progname, "sort_p") == 0) {
        testFunc(sort_p, "sort_p");
    } else if (strcmp(progname, "sort_c") == 0) {
        testFunc(sort_c, "sort_c");
    } else if (strcmp(progname, "sort_m") == 0) {
        testFunc(sort_m, "sort_m");
    } else if (strcmp(progname, "sort_f") == 0) {
        testFunc(sort_f, "sort_f");
    } else {
        // Default: run all
        testFunc(sort_a, "sort_a");
        testFunc(sort_i, "sort_i");
        testFunc(sort_p, "sort_p");
        testFunc(sort_c, "sort_c");
        testFunc(sort_m, "sort_m");
        testFunc(sort_f, "sort_f");
    }

    benchmark(n, trials);
    return 0;
}
