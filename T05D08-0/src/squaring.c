#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == -1) {
        printf("n/a");
        return 1;
    }
    squaring(data, n);
    output(data, n);
    return 0;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n > NMAX || *n < 1) {
        return -1;
    }
    for (int *p = a; p - a < *n - 1; p++) {
        if (scanf("%d", p) != 1) {
            return -1;
        }
    }
    if (scanf("%d", &(a[*n - 1])) == 1) {
        if (getchar() != '\n') {
            return -1;
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", a[i]);
    }
    printf("%d", a[n - 1]);
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        a[i] *= a[i];
    }
}