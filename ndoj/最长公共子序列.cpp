#include <iostream>
#include <string>
using namespace std;

const int MAX = 1e3;
int flag[MAX + 5][MAX + 5];
char s1[MAX + 5], s2[MAX + 5];
int dp[MAX + 5][MAX + 5];

void LCS()
{
    memset(dp, 0, sizeof(dp));
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= strlen(s1); i++)
    {
        for (int j = 1; j <= strlen(s2); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1, flag[i][j] = 0;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j], flag[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i][j - 1], flag[i][j] = -1;
            }
        }
    }
}
void PrintLCS(int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (flag[i][j] == 0)
    {
        PrintLCS(i - 1, j - 1);
        cout << s1[i - 1];
    }
    else if (flag[i][j] == 1)
    {
        PrintLCS(i - 1, j);
    }
    else
    {
        PrintLCS(i, j - 1);
    }
}
int main()
{
    while (cin >> s1 >> s2)
    {
        LCS();
        PrintLCS(strlen(s1), strlen(s2));
        cout << endl;
    }
}
