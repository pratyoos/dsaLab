#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int A[], int l, int r) {
    int X = l + 1, Y = r, pivot = A[l], temp;

    while (X <= Y) {
        while (X <= r && A[X] <= pivot)
            X++;
        while (Y > l && A[Y] >= pivot)
            Y--;
        if (X < Y) {
            temp = A[X];
            A[X] = A[Y];
            A[Y] = temp;
        }
    }

    temp = A[Y];
    A[Y] = A[l];
    A[l] = temp;
    return Y;

}

void quickSort(int A[], int l, int r)
{
    int p;
    if (l < r)
    {
        p = partition(A, l, r);
        quickSort(A, l, p-1);
        quickSort(A, p+1, r);
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
    quickSort(A,0,n-1);
    end = clock();
    // display(A,n);
    diff = end-start;
    printf("The time taken is %f seconds.\n", (double)diff/CLOCKS_PER_SEC);
    return 0;
}


//time taken for sorting 10000 elements: 0.001682 s
//time taken for sorting 100000 elements: 0.024852 s

