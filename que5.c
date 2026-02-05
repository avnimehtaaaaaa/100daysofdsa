#include <stdio.h>
int main() {
    int p, q;
    int i = 0, j = 0;

    scanf("%d", &p);
    int log1[p];
    for (i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    scanf("%d", &q);
    int log2[q];

    for (j = 0; j < q; j++) {
        scanf("%d", &log2[j]);
    }

    i = 0;
    j = 0;

    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }

    return 0;
}
/*
5
10 20 30 50 70
4
15 25 40 60
10 15 20 25 30 40 50 60 70
*/
