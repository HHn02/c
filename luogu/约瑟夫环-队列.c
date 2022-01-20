#include"stdio.h"
typedef int QElemType;
typedef struct 
{
    QElemType data[105];
    int front;
    int rear;
}SqQueue;
void initqueue(SqQueue *q)
{
    q->front=0;
    q->rear=0;
}
void EnQueue(SqQueue *q,int n,int t)
{
    q->data[q->rear]=t;
    q->rear=(q->rear+1)%n;
}
void DeQueue(SqQueue *q,int n)
{
    q->data[q->front]=0;
    q->front=(q->front+1)%n; 
}
void SwitchQueue(SqQueue *q,int n)
{
    int t=q->data[q->front];
    DeQueue(q,n);
    EnQueue(q,n,t);
    
}

int main()
{
    SqQueue Q;
    int n,m;
    scanf("%d %d",&n,&m);
    initqueue(&Q);
    for (int i = 0; i < n; i++)
    {
        EnQueue(&Q,n,i+1);
    }
    
    int k=0;
    while (k!=n)
    {
        for (int i = 0; i < m-1; i++)
        {
            SwitchQueue(&Q,n); 
        }
        printf("%d ",Q.data[Q.front]); 
        DeQueue(&Q,n);
        k++;
        
    }
    




}