import time
import random

def quickSort(A, low, high):
    if low < high:
        p = partition(A, low, high)
        quickSort(A, low, p - 1)
        quickSort(A, p + 1, high)

def partition(A, low, high):
    pivot = A[low]
    i = low + 1
    j = high

    while True:
        while i <= high and A[i] < pivot:
            i += 1
        while j >= low and A[j] > pivot:
            j -= 1
        if i < j:
            temp = A[i]
            A[i] = A[j]
            A[j] = temp
        else:
            break
    temp = A[low]
    A[low] = A[j]
    A[j] = temp
    return j

def display(A, n):
    for i in range(n):
        print(A[i] , end=" ")
    print()

A = []
n = int(input("Enter n: "))
for i in range(n):
    A.append(random.randint(0, 1000))

start = time.time()
display(A, n)
quickSort(A, 0, n-1)
end = time.time()
display(A, n)
print(f"The time taken is {end - start:f} seconds.")