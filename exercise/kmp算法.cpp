#include <iostream>
using namespace std;
void get_next(string t, int next[])
{
    int k = -1, j = 0;
    next[0] = -1;
    while (j < t.length() - 1)
    {
        if (k == -1 || t[j] == t[k])
        {
            k++;
            j++;
            next[j] = k;
        }
        else
            k = next[k];
    }
}
void get_nextval(string t, int next[])
{
    int k = -1, j = 0;
    next[0] = -1;
    while (j < t.length() - 1)
    {
        if (k == -1 || t[j] == t[k])
        {
            k++;
            j++;
            if (t[j] == t[k])
            {
                next[j] = next[k];
            }
            else
                next[j] = k;
        }
        else
            k = next[k];
    }
}
int kmp(string s, string t, int next[])
{
    int i, j;
    i = j = 0;
    while (i < s.length() && j < t.length())
    {
        if (j == -1 || s[i] == t[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j == t.length())
        return i - j;
    else
        return -1;
}
/*                 */
void kmp_pre(const string &t,const vector<int> & pre){
    int n = t.size();
    for(int i=1,j=0;i<n;++i){
        while (j>0&&t[i]!=t[j])
            j=pre[j-1];
        if(t[j]=t[i])
            ++j;
        pre[i]=j;    
    }
}
int kmp(const string &s,const string &t,const vector<int>& pre ){
    int n = s.size();
    int m = t.size();
    for(int i = 0,j = 0;i < n;++i){
        while(j>0&&s[i]!=t[j])
            j=pre[j];
        if(s[i]==t[j])
            ++j;
        if(j==m)
            return  i-m+1;
    }
    return -1;
}

