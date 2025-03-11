#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int A[], int n) {
    int i, j, least, pos;
    for (i = 0; i < n - 1; i++) {
        least = A[i];
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < least) {
                least = A[j];
                pos = j;
            }
        }
        if (i != pos) {
            int temp = A[i];
            A[i] = A[pos];
            A[pos] = temp;
        }
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
    display(A,n);
    start = clock();
    selectionSort(A,n);
    end = clock();
    display(A,n);
    diff = end-start;
    printf("The time taken is %f seconds.\n", (double)diff/CLOCKS_PER_SEC);
    return 0;
}

//time taken for sorting 10 elements: 0.000005 s
//time taken for sorting 100 elements: 0.000034 s
//time taken for sorting 1000 elements: 0.000997 s
//time taken for sorting 10000 elements: 0.069093 s
//time taken for sorting 100000 elements: 5.771782 s