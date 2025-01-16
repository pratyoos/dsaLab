import time
import random

def merge(A, l, m, r):
    i = l
    j = m + 1
    k = 0
    B = [0] * (r - l + 1)

    while i <= m and j <= r:
        if A[i] < A[j]:
            B[k] = A[i]
            i += 1
        else:
            B[k] = A[j]
            j += 1
        k += 1

    while i <= m:
        B[k] = A[i]
        i += 1
        k += 1

    while j <= r:
        B[k] = A[j]
        j += 1
        k += 1

    for i in range(l, r + 1):
        A[i] = B[i - l]

def mergeSort(A, l, r):
    if l < r:
        m = int((l + r) / 2)
        mergeSort(A, l, m)
        mergeSort(A, m + 1, r)
        merge(A, l, m, r)

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
mergeSort(A, 0, n - 1)
end = time.time()
display(A, n)
print(f"The time taken is {end - start:f} seconds.")