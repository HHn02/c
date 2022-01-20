#include<iostream>
using namespace std;
int a[100];
int val;
int func(int left,int right)
{
    if(left<=right)
    {
        int mid = left+((right-left)>>1);
        if(a[mid]==val)
            return mid+1;
        else if(a[mid]<val)
            return func(mid+1,right);
        else
            return func(left,mid-1);
    }
    return 0;
    /* int left=0,right =n-1;
    while (left<=right)
    {
        int mid = left+((right-left)>>1);
        if(a[mid]==val)
            return mid+1;
        else if(a[mid]<val)
            left=mid+1;
        else
            right=mid-1;
    }
    return 0; */
}
int main()
{
    int n;
    cin >> n >> val;
    for(int i=0;i<n;i++)
    cin >> a[i];
    cout << func(0,n-1) << endl;
    return 0;

}