import time
import random

def mergeSort(A, n):
    if n > 1:
        mid = n // 2
        L = A[:mid]
        R = A[mid:]
        mergeSort(L, mid)
        mergeSort(R, n - mid)
        i = j = k = 0
        while i < mid and j < n - mid:
            if L[i] < R[j]:
                A[k] = L[i]
                i += 1
            else:
                A[k] = R[j]
                j += 1
            k += 1
        while i < mid:
            A[k] = L[i]
            i += 1
            k += 1
        while j < n - mid:
            A[k] = R[j]
            j += 1
            k += 1

def display(A, n):
    for i in range(n):
        print(A[i] , end=" ")
    print()

A = []
n = int(input("Enter n: "))
for i in range(n):
    A.append(random.randint(0, 100000))

start = time.time()
display(A, n)
mergeSort(A, n)
end = time.time()
display(A, n)
print(f"The time taken is {end - start:f} seconds.")