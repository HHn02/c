#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 10;
int dp[MAX][MAX];
int pos[MAX][MAX];
int a[MAX];
int s[MAX];
//char ans[50];
int n;
queue<char>ans;
void find_pos(int i,int j)
{
    int n=pos[i][j];
    if(n==0)
    {
        ans.push('(');
        ans.push(a[n-1]+48);
        ans.push(',');
        return ;
    }
        
    if(i==n)   
    {
        ans.push('(');
        ans.push(a[n-1]+48);
        ans.push(',');
        ans.push(a[n]+48);
        ans.push(')');
        return ;
    }
    find_pos(i,n);
    find_pos(n+1,j);
}
int main()
{
    memset(dp,0x3f,sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i]=s[i-1]+a[i];
        dp[i][i]=0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int start = 1; start+len-1 <= n ; start++)
        {
            int end=start+len-1;
            for (int k = start ; k < end; k++)
            {
                int t=dp[start][end];
                dp[start][end]=min(dp[start][end],dp[start][k]+dp[k+1][end]+s[end]-s[start-1]);
                if(t!=dp[start][end])
                    pos[start][end]=k;
            }
        }
    }
    cout << dp[1][n] << endl;
    find_pos(1,n);
    return 0;
}