#include<iostream>
using namespace std;
int a[1000];
int n;
void output()
{
    for(int i=1;i<=n;i++)
        cout << a[i];
    cout << endl;
}
void perm(int m)
{
    int t;
    if(m==n)
    {
        output();
        return ;
    }
    for (int i = m; i <=n; i++)
    {
        t=a[i];a[i]=a[m];a[m]=t;
        perm(m+1);
        t=a[i];a[i]=a[m];a[m]=t;
    }
    
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        a[i]=i;
    perm(1);
    return 0;   
}