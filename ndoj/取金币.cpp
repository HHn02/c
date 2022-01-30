#include <iostream>
#include <algorithm>
using namespace std;
int a[1001][1001];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j - 1] >= a[i - 1][j])
            {
                a[i][j] += a[i][j - 1];
            }
            else
            {
                a[i][j] += a[i - 1][j];
            }
        }
    }
    cout << a[n][n] << endl;
    return 0;
}