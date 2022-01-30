#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
int r[205][205];
int dp[205];
int n;
int T[205];
int k=0;
int getmin()
{
    dp[1]=0;
    dp[2]=r[1][2];
    for (int i = 3; i <= n ; i++)
    {
        dp[i]=r[1][i];
        int t;
        for (int j = 2; j < i; j++)
        {
            if(i==n)
                t=dp[i];
            dp[i]=min(dp[i],dp[j]+r[j][i]);
            if(i==n)
            {
                if(dp[i]!=t)
                T[k++]=j;
            }
        }
        
    }
    return dp[n];
}
int main()
{
    
    cin >> n;
    for (int i = 1; i <n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            cin >> r[i][j];
        }
        
    }
    //cout << getmin() << endl;
    getmin();
    cout << n;
    for (int i = k-1; i>=0; i--)
    {
        cout << "<--" << T[i];
    }
    cout <<"<--"<< '1' << endl;
    return 0;
}