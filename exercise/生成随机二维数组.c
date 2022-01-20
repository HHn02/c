#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
    int i=0,j=0;
    unsigned int n,b;
    int a[666][666];
    srand((unsigned)time(NULL));
    rand()%201+0;
    //printf("%d",rand());
    for ( i = 0;i<50 ; i++)
    {
        for ( j = 0;j<50; j++)
        {
          a[i][j]=rand()%10+0;
          printf("%-1d\x20",a[i][j]);
        }
        //printf("\n");
    }

 /*   scanf("%d",&n);
   loop:for ( int k = 0; k < n; k++)
  {
      scanf("%d",&b);
      printf("\n");
      for (i=0; i < 666; i++)
    {
      for (j=0 ; i < 666; j++)
      {
          if (a[i][j]==b)
          {
            printf("%d %d",i+1,j+1);
            printf("\n");
            goto loop;
          }
          
      }
      
    }
  }
  return 0; */
}