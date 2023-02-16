#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    int n = 0;
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
        return 1;
    }
    double *data = (double *)malloc(n * sizeof(double));
    if (data == NULL) {
        printf("n/a");
        return 1;
    }
    if (input(data, n)) {
        printf("n/a");
        free(data);
        return 1;
    }
    if (make_decision(data, n)) {
        printf("YES");
    } else {
        printf("NO");
    }
    free(data);
    return 0;
}
