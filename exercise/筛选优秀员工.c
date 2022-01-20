#include"stdio.h"
#include"string.h"
void initialize_array(int n,int *pa);
void selectout(int n,int (*ph)[3]);
void change(int (*p1)[3],int (*p2)[2]);   
int output(int *p);   
int main()
{
    int a[100][3],b[100][2];
    int n;
    scanf("%d",&n);
    initialize_array(n,&a[0][0]);
    selectout(n,&a[0]);
    change(&a[0],&b[0]);
    output(&b[0][0]);
}
void initialize_array(int n,int *pa){
  
   for (int i = 0; i < n; i++)
   {
       *pa=i+1;
        pa++;
        for (int j = 0; j < 2; j++)
        {
           scanf("%d",pa);
           pa++;
        }
   }
}
void selectout(int n,int (*ph)[3]){  
//先比较加班时长，长的上移动，一样再比较正常时长，长的上移，再一样比较员工号，小的上移。
    int t[3]; //临时空间
    for (int i = 0; i < n-1; i++)                   //根据加班时长，将整个二维数组排列。
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (*(*(ph+j)+1)+*(*(ph+j)+2)<*(*(ph+j+1)+1)+*(*(ph+j+1)+2))           //先判总和
            {
                memcpy(t,ph+j,12);
                memcpy(ph+j,ph+j+1,12);
                memcpy(ph+j+1,t,12);  
            }
            else if (*(*(ph+j)+1)+*(*(ph+j)+2)==*(*(ph+j+1)+1)+*(*(ph+j+1)+2)&&*(*(ph+j)+1)<*(*(ph+j+1)+1))      //总合相等，判正常时长
            {
                memcpy(t,ph+j,12);
                memcpy(ph+j,ph+j+1,12);
                memcpy(ph+j+1,t,12);  
            }                                                                                               //总合相等，正常时间也相等，判员工号
            else if (*(*(ph+j)+1)+*(*(ph+j)+2)==*(*(ph+j+1)+1)+*(*(ph+j+1)+2)&&*(*(ph+j)+1)==*(*(ph+j+1)+1)&&*(*(ph+j)+0)<*(*(ph+j+1)+0))
            {
                memcpy(t,ph+j,12);
                memcpy(ph+j,ph+j+1,12);
                memcpy(ph+j+1,t,12);  
            }
            
        }
    }
    
}
void change(int (*p1)[3],int (*p2)[2]){
    for (int i = 0; i < 5; i++)
    {
        *(*(p2+i)+0)=*(*(p1+i)+0);
        *(*(p2+i)+1)=*(*(p1+i)+1)+*(*(p1+i)+2);
    }     
}
int output(int *p){
    int k=0;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",*p);
        p++;
        k++;
        if (k%2==0)
        {
            printf("\n");
        }
    }
}