import random
import time

def selectionSort(A, n):
    for i in range(n - 1):
        least = A[i]
        pos = i
        for j in range(i + 1, n):
            if A[j] < least:
                least = A[j]
                pos = j
        if i != pos:
            A[pos] = A[i]
            A[i] = least


def display(A, n):
    for i in range(n):
        print(A[i], end=" ")
    print()

A = []
n = int(input("Enter n: "))

for i in range(n):
    A.append(random.randint(0, 100000))

start = time.time()
display(A, n)
selectionSort(A, n)
end = time.time()
display(A, n)
print(f"The time taken is {end - start:f} seconds.")
