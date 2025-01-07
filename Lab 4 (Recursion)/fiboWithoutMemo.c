// Recursive Implementation of nth Fibonacci Number without Memoization

#include<stdio.h>

int fibo(int n)
{
    if(n==1 || n == 2)
        return 1;
    else
        return fibo(n-1) + fibo(n-2);
}

int main()
{
    int num, ans;
    printf("Enter a number: ");
    scanf("%d", &num);
    ans = fibo(num);
    printf("The %dth term in fibonacci series is %d\n", num, ans);
}
