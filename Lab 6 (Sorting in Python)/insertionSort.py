import time
import random

def insertionSort(A, n):
    for i in range(1, n):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = key

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
insertionSort(A, n)
end = time.time()
display(A, n)
print(f"The time taken is {end - start:f} seconds.")