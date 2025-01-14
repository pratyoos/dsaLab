#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int A[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int B[r - l + 1];
    
    while (i <= m && j <= r) {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= m)
        B[k++] = A[i++];

    while (j <= r)
        B[k++] = A[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        A[i] = B[k];
}

void mergeSort(int A[], int l, int r) {
    int m;
    if (l < r) {
        m = (l + r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}


void display(int A[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(){
    int A[100000], n, i;
    clock_t start, end, diff;
    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        A[i] = rand();
    display(A,n);
    start = clock();
    mergeSort(A,0,n-1);
    end = clock();
    display(A,n);
    diff = end-start;
    printf("The time taken is %f seconds.\n", (double)diff/CLOCKS_PER_SEC);
    return 0;
}

//time taken for sorting 10000 elements: 0.002848 s
//time taken for sorting 100000 elements: 0.029574 s