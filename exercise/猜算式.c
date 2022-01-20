#include "stdio.h"
#include "string.h"
int ans = 0;
int a[10], b[10];
int mid[51];
int nums(int n, int m, int arr[])
{
    int num = 0;
    for (int i = n; i <= m; i++)
    {
        num = num * 10 + arr[i];
    }
    return num;
}
void func(int p)
{
    if (p == 10)
    {
        if (nums(1, 2, a) * nums(3, 4, a) == nums(5, 6, a) * nums(7, 9, a))
        {
            ans++;
        }
        return;
    }
    int tb[10] = {};
    for (int i = 1; i < 10; i++)
    {
        
        if (b[i] == 0)
        {
            memcpy(tb, b, sizeof(int) * 10);
            a[p] = i;
            b[i] = 1;
            func(p + 1);
            memcpy(b, tb, sizeof(int) * 10);
        }
    }
}
int main()
{
    func(1);
    printf("%d", ans/2);
    return 0;
}