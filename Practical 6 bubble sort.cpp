#include <stdio.h>

#define MAX 100

int main() {
    int a[MAX], n, temp;

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

    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}
