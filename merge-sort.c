#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc+1]) {
    double list[argc-1];
    for (size_t i = 0; argv[i+1]; ++i) {
        list[i] = strtod(argv[i+1], 0);
        printf("%.2f ", list[i]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}