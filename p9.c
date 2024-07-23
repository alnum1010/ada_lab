#include <stdio.h>
#include<stdlib.h>
#include <time.h>

void selsort(int a[], int n) {
    int i, j, small, pos, temp;
    for (j = 0; j < n - 1; j++) {
        small = a[j];
        pos = j;
        for (i = j + 1; i < n; i++) {
            if (a[i] < small) {
                small = a[i];
                pos = i;
            }
        }
        temp = a[j];
        a[j] = small;
        a[pos] = temp;
    }
}

int main() {
    int a[10000], i, n;
    clock_t start, end;
    double dura;

    printf("\nEnter the n value: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        a[i] = rand();

    start = clock();
    selsort(a, n);
    end = clock();

    dura = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    printf("\nTime taken is: %f -seconds", dura);
    

    printf("\n");
    return 0;
}