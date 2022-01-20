#include "stdio.h"

int j = 0;
int M = -99;
int max;
void Cal(int a[], int n, int m, int k, int sum)
{
    if (n == -1)
    {
        if (sum >= M && sum <= max)
            M = sum;
        return;
    }
    for (int i = m; i < k - n; i++)
    {
        sum += a[i];
        Cal(a, n - 1, i + 1, k, sum);
        sum -= a[i];
    }
}
int main()
{
    int n;
    int a[20] = {};
    scanf("%d %d", &max, &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        Cal(a, i - 1, 0, n, 0);
    }
    printf("%d", M);
    return 0;
}