// Recursive Implementation of Towers of Hanoi

#include <stdio.h>

void toh(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", src, dst);
        return;
    }
    toh(n - 1, src, dst, tmp);
    printf("Move disk %d from %c to %c\n", n, src, dst);
    toh(n - 1, tmp, src, dst);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
    return 0;
}