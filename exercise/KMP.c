#include"stdio.h"
#include"string.h"
void get_next(char string[],int next[])
{

    int length=strlen(string);
    int j,k;
    j=0;
    k=-1;
    next[0]=-1;
    while (j<length-1)
    {
        if (k==-1||string[j]==string[k])
        {
            next[++j]=++k;
        }
        else
            k=next[k];
    }
    
}
void get_nextval(char string[],int nextval[])
{
    int length=strlen(string);
    int j,k;
    j=0;
    k=-1;
    nextval[0]=-1;
    while (j<length-1)
    {
        if (k==-1||string[j]==string[k])
        {
            ++j;
            ++k;
            if (string[j]!=string[k])
            {
                nextval[j]=k;
            }
            else
                nextval[j]=nextval[k];
        }
        else    
            k=nextval[k];
    }
    
}
int main()
{
    int next[9]={};
    char ch[]="ababaaaba";
    get_nextval(ch,next);
    for (int i = 0; i < 9; i++)
    {
        printf("%d ",next[i]);
    }

}