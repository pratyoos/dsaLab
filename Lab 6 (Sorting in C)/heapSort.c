// heap sort in c program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int A[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && A[left] > A[largest])
        largest = left;
    if (right < n && A[right] > A[largest])
        largest = right;
    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
    for (i = n - 1; i > 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapify(A, i, 0);
    }
}

void display(int A[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[100000], n, i;
    clock_t start, end, diff;
    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        A[i] = rand();
    display(A,n);
    start = clock();
    heapSort(A, n);
    end = clock();
    display(A,n);
    diff = end - start;
    printf("The time taken is %f seconds.\n", (double)diff / CLOCKS_PER_SEC);
    return 0;
}

