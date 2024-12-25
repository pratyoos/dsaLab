// Tail Recursive Implementation of Factorial

#include<stdio.h>

int fact(int n, int a)
{
    if(n == 0)
    {
        return a;
    }
    return fact(n-1, a*n);
}

int main()
{
    int num, ans;
    printf("Enter the number: ");
    scanf("%d", &num);
    ans = fact(num,1);
    printf("The factorial of %d is %d", num, ans);
}