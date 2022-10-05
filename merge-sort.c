#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define KNRM "\x1b[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"

void msort(double* list, int size) {
    if (size == 1) {
        return;
    }

    int lsize = size / 2;
    int rsize = size - lsize;

    double left[lsize];
    for (int i = 0; i < lsize; ++i) {
        left[i] = list[i];
    }
    msort(left, lsize);

    double right[rsize];
    for (int i = 0; i < rsize; ++i) {
        right[i] = list[lsize+i];
    }
    msort(right, rsize);

    int i = 0;
    int j = 0;
    while (i + j < size) {
        if (i == lsize) {
            while (j < rsize) {
                list[i+j] = right[j];
                ++j;
            }
        } else if (j == rsize) {
            while (i < lsize) {
                list[i+j] = left[i];
                ++i;
            }
        } else {
            if (left[i] < right[j]) {
                list[i+j] = left[i];
                ++i;
            } else {
                list[i+j] = right[j];
                ++j;
            }
        }
    }

    return;
}

void test_merge_sort_doubles() {
    double list[5] = {1, 5, 2, 4, 3};
    double checklist[5] = {1, 2, 3, 4, 5};
    msort(list, 5);

    int i = 0;
    while (i < 5) {
        if (list[i] != checklist[i]) {
            break;
        }
        ++i;
    }

    if (i == 5) {
        printf("%s[PASSED] ", KGRN);
    } else {
        printf("%s[FAILED] ", KRED);
    }
    printf("%stest merge sort doubles\n", KNRM);
}

int main(int argc, char* argv[argc+1]) {
    if (argc > 1) {
        double list[argc-1];
        for (size_t i = 0; argv[i+1]; ++i) {
            list[i] = strtod(argv[i+1], 0);
            printf("%.2f ", list[i]);
        }
        printf("\n");

        msort(list, argc-1);

        for (size_t i = 0; i < argc-1; ++i) {
            printf("%.2f ", list[i]);
        }
        printf("\n");
    } else {
        test_merge_sort_doubles();
    }

    return EXIT_SUCCESS;
}