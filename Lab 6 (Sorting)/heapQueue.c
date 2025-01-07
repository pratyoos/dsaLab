// Heap sort as a priority queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void insert(int arr[], int *n, int element) {
    *n = *n + 1;
    arr[*n - 1] = element;
    for (int i = *n / 2 - 1; i >= 0; i--) {
        heapify(arr, *n, i);
    }
}

int deleteMax(int arr[], int *n) {
    int max = arr[0];
    arr[0] = arr[*n - 1];
    *n = *n - 1;
    heapify(arr, *n, 0);
    return max;
}

int main() {
    int n = 0, i, arr[MAX];
    insert(arr, &n, 10);
    insert(arr, &n, 20);
    insert(arr, &n, 15);
    insert(arr, &n, 40);
    insert(arr, &n, 50);
    insert(arr, &n, 100);
    printf("Max element: %d\n", deleteMax(arr, &n));
    printf("Max element: %d\n", deleteMax(arr, &n));
    printf("Max element: %d\n", deleteMax(arr, &n));
    return 0;
}

