#include <stdio.h>

#define MAX 100

int a[MAX];

// Partition function
int partition(int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

// Quick sort
void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

// Main function
int main() {
    int n;

    printf("Enter number of elements: ");

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size\n");
        return 1;
    }

    printf("Enter elements: ");

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Invalid input\n");
            return 1;
        }
    }

    quickSort(0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}
