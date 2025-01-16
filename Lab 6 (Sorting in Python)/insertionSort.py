import time
import random

def insertionSort(A, n):
    for i in range(1, n):
        temp = A[i]
        j = i - 1
        while j >= 0 and A[j] > temp:
            A[j + 1] = A[j]
            j = j - 1
        A[j + 1] = temp

def display(A, n):
    for i in range(n):
        print(A[i] , end=" ")
    print()  # to print new line after endign of loop

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