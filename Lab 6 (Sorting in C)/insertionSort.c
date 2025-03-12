// O(n^2)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int A[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > temp) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = temp;
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
    srand(time(NULL));
    clock_t start, end, diff;
    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        A[i] = rand();
    // display(A,n);
    start = clock();
    insertionSort(A,n);
    end = clock();
    // display(A,n);
    diff = end-start;
    printf("The time taken is %f seconds.\n", (double)diff/CLOCKS_PER_SEC);
    return 0;
}

//time taken for sorting 10 elements: 0.000010 s
//time taken for sorting 100 elements: 0.000016 s
//time taken for sorting 1000 elements: 0.002096 s
//time taken for sorting 10000 elements: 0.059925 s
//time taken for sorting 100000 elements: 3.184326 s