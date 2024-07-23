#include <stdio.h>
#include<stdlib.h>
#include <time.h>


void swap(int* p1, int* p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(a, 0, n - 1);
    end = clock();

    dura = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    printf("\nTime taken is: %f milli-seconds", dura);
    

    printf("\n");
    return 0;
}
