import random
import time

def partition(A, l, r):
    X = l + 1
    Y = r
    pivot = A[l]
    
    while (X <= Y):
        while X <= r and A[X] <= pivot:
            X = X + 1
        while Y > l and A[Y] >= pivot:
            Y = Y - 1
        if X < Y:
            temp = A[X]
            A[X] = A[Y]
            A[Y] = temp
        else:
            break
        
    temp = A[Y]
    A[Y] = A[l]
    A[l] = temp
    return Y

def quickSort(A, l, r):
    if l < r:
        p = partition(A, l, r)
        quickSort(A, l, p - 1)
        quickSort(A, p + 1, r)

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
quickSort(A, 0, n - 1)
end = time.time()
display(A, n)
print(f"The time taken is {end - start:f} seconds.")
