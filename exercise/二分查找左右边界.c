#include"stdio.h"

int right_bound(int target,int array[],int n)
{
    int left=0,right=n;
    while (left<right)
    {
        int mid=left+((right-left)>>1);
        if (array[mid]==target)
        {
            left=mid+1;
        }
        else if (array[mid]<target)
        {
            left=mid+1;
        }
        else if (array[mid]>target)
        {
            right=mid;
        }
    } 
    if (left==n)
    {
        if (array[left]==target)
        {
            return left-1;
        }
        else
        return -1;
    }  
    else if(left==0)
    {
        return left;
    }       
    else if (array[left-1]<target)
    {
        return left;
    }
    else
        return left-1;
}

int left_bound(int target,int array[],int n)
{
    int left=0,right=n;
    while (left<right)
    {
        int mid=left+((right-left)>>1);
        if (array[mid]==target)
        {
            right=mid;
        }
        else if(array[mid]<target)
        {
            left=mid+1;
        }
        else if(array[mid]>target)
        {
            right=mid;
        }
    }
    if(left==n)
        return n-1;
    else if (array[left]==target)
    {
        return array[left];
    }
    else
        return array[left-1];
        
}

int main()
{
    int a[]={16,16,17,18};
    int n=right_bound(18,a,4);
    printf("%d",n);
}