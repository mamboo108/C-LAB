#include <stdio.h>

void merge(int a[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[high + 1];  // Temporary array

    // Merge the two halves into b[]
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left half, if any
    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements of right half, if any
    while (j <= high) {
        b[k] = a[j];
        j++;
        k++;
    }

    // Copy merged elements back into original array
    for (int m = low; m <= high; m++) {
        a[m] = b[m];
    }
}

void partition(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        partition(a, low, mid);
        partition(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    partition(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
