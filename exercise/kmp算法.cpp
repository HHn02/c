#include<iostream>
using namespace std;
void get_next(string t,int next[]){
    int k=-1,j=0;
    next[0]=-1;
    while (j<t.length()-1)
    {
        if(k==-1||t[j]==t[k]){
            k++;j++;
            next[j]=k;
        }
        else
            k=next[k];
    }

}
void get_nextval(string t,int next[]){
    int k=-1,j=0;
    next[0]=-1;
    while (j<t.length()-1)
    {
        if(k==-1||t[j]==t[k]){
            k++;j++;
            if(t[j]==t[k]){
                next[j]=next[k];
            }
            else
                next[j]=k;
        }
        else
            k=next[k];
    }
    
}
int kmp(string s,string t,int next[]){
    int i,j;
    i=j=0;
    while (i<s.length()&&j<t.length())
    {
        if(j==-1||s[i]==t[j]){
            ++i;++j;
        }
        else
            j=next[j];
    }
    if(j==t.length())
        return i-j;
    else
        return -1;
}