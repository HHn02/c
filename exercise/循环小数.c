#include "stdio.h"
int main()
{
    int n, m;
    scanf("%d,%d", &n, &m);
    int a[100] = {};
    int b[100] = {};
    int p = n / m;
    int q = n % m;
    int j = 0;
    int flag = 0;
    while (1)
    {
        if (q == 0)
        {
            flag = 1;
            break;
        }
        int t1 = q * 10 / m;
        int t2 = q * 10 % m;
        q = q * 10 % m;
        a[j++] = t1;
        b[t1 * 10 + t2]++;
        if (b[t1 * 10 + t2] == 2)
        {
            break;
        }
    }

    if (flag == 1)
    {
        printf("%d.", p);
        for (int i = 0; i < j; i++)
        {
            printf("%d", a[i]);
        }
    }
    else
    {
        j--;
        if (a[j] == a[0])
        {
            printf("%d.", p);
            for (int i = 0; i < j; i++)
            {
                if (i == 0 && i == j - 1)
                    printf("[%d]", a[i]);
                else if (i == 0)
                    printf("[%d", a[i]);
                else if (i == j - 1)
                    printf("%d]", a[i]);
                else
                    printf("%d", a[i]);
            }
        }
        else
        {
            printf("%d.", p);
            int k = 0;
            for (k = 0;; k++)
            {
                if (a[k] == a[j])
                    break;
                printf("%d", a[k]);
            }
            for (int i = k; i < j; i++)
            {
                if (i == k && i == j - 1)
                    printf("[%d]", a[i]);
                else if (i == k)
                    printf("[%d", a[i]);
                else if (i == j - 1)
                    printf("%d]", a[i]);
                else
                    printf("%d", a[i]);
            }
        }
    }
}