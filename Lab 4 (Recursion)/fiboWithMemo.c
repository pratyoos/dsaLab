// Recursive Implementation of nth Fibonacci Number with Memoization

#include <stdio.h>
#define MAX 1000
int memo[MAX];

void initialize_memo() {
    for (int i = 0; i < MAX; i++) {
        memo[i] = -2;
    }
}

int fibo(int n) {
    if (n <= 0) 
        return 0;
    if (n == 1) 
        return 1;
    if (memo[n] != -2) {
        return memo[n];
    }
    memo[n] = fibo(n - 1) + fibo(n - 2);
    return memo[n];
}

int main() {
    int num, ans;
    initialize_memo();
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    ans = fibo(num);
    printf("The %dth term in fibonacci series is %d\n", num, ans);
    return 0;
}
