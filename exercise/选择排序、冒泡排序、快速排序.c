#include "stdio.h"
void quicksort(int arry[],int L,int R);
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a[] = {2, 3, 6, 4, 2, 6, 7, 4, 10, 21, 20};
    // 选择排序
    int i, j,temp;
    for (i = 0; i < 10; i++)
    {
        int min = i;
        for (j = i + 1; j < 11; j++)
        {
            if (a[j] < a[min])
            {
                min = j;        //记录下标
            }    
               
        } 
        swap(&a[min], &a[i]);                
            
    }
    for (int i = 0; i < 11; i++)
    {
        printf("%d ", a[i]);
    }
    // 冒泡排序
    int temp;
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }

        }

    }
    quicksort(a,0,10);
    for(int i=0;i<11;i++)
    {
        printf("%d ",a[i]);
    }
    
}
void quicksort(int arry[],int L,int R)
{
    if(L>R)
        return ;
    int left=L,right=R;
    int pivot=arry[left];
    while (left<right)
    {
        while (left<right&&arry[right]>=pivot)
        {
            right--;
        }
        if (left<right)
        {
            arry[left]=arry[right];
        }
        while (left<right&&arry[left]<=pivot)
        {
            left++;
        }
        if(left<right)
        {
            arry[right]=arry[left];
        }
        if(left>=right)
        {
            arry[left]=pivot;
        }
    }
    quicksort(arry,L,right-1);
    quicksort(arry,right+1,R);
}