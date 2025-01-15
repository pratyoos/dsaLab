import time
import random

def bubbleSort(A, n):
    for i in range(n - 1):
        for j in range(n - i - 1):
            if A[j] > A[j + 1]:
                A[j], A[j + 1] = A[j + 1], A[j]

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
bubbleSort(A, n)
end = time.time()
display(A, n)
print(f"The time taken is {end - start:f} seconds.")
