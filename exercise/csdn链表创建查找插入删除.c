#include <stdio.h>
#include <stdlib.h>
typedef char ListData;

typedef struct node//链表节点
{
    ListData data;
    struct node *link;
}ListNode;
                                    //struct node ==ListNode
                                    //struct node*==LinkList 
typedef ListNode* LinkList;

LinkList CreatListF()//头插法创建链表
{
    ListData ch;
    ListNode *q;
    LinkList head=(LinkList)malloc(sizeof(ListNode));
    head->link=NULL;
    printf("头插法创建链表:Please input values of the List:\n");
    while((ch=getchar())!='\n')
    {
        q=(ListNode*)malloc(sizeof(ListNode));
        q->data=ch;//建立新节点
        q->link=head->link;//插入到表前端
        head->link=q;
    }
    return head;
}

LinkList CreatListR()//尾插法创建链表
{
    ListData ch;
    LinkList head=(LinkList)malloc(sizeof(ListNode));
    ListNode *q,*r=head;
    head->link=NULL;
    printf("尾插法创建链表:Please input values of the List:\n");
    while((ch=getchar())!='\n')
    {
        q=(ListNode*)malloc(sizeof(ListNode));
        q->data=ch;
        q->link=r->link;        //通过r指针保证正序插入数据
        r->link=q;
        r=q;
    }
    return head;
}

LinkList InsertList(LinkList first,ListData x,int i)//在链表的第i个节点处插入新元素
{
    ListNode *p=first;
    for(int k=0;k<i-1;k++)//找到第i-1个结点
    {
        if(p==NULL)break;
        else p=p->link;         //p指向下个结点

    }
    if(i<=0||p==NULL) printf("无效的插入位置\n");//参数i值不合理
    else
    {
        ListNode *newnode=(ListNode*)malloc(sizeof(ListNode));//创建新节点
        newnode->data=x;
        newnode->link=p->link;
        p->link=newnode;
    }
    return first;
}

LinkList DeleteList(LinkList first,int i)//删除链表中的某个节点
{
    ListNode *p=first,*q;
    for(int k=0;k<i-1;k++)//从第0个开始，寻找第i-1个结点
    {
        if(p==NULL)break;
        else p=p->link;
    }
    if(p==NULL||p->link==NULL)
        printf("无效的删除位置\n");//i值不合理或为空表
    else
    {
        q=p->link;
        p->link=q->link;
        free(q);
    }
    return first;
}

int Findv(LinkList first,ListData x)
{
    ListNode *p=first;
    int s=0;
    while(p!=NULL&&p->data!=x)
        {p=p->link;s++;}
    if(p==NULL)
    {
        printf("查找失败\n");
        return 0;
    }
    else return s;
}

ListNode* Finds(LinkList first,int i)
{
    ListNode *p=first;
    for(int k=0;k<i;k++)
    {
        if(p==NULL) break;
        p=p->link;
    }
    if(i<1||p==NULL)//i值不合理
    {
        printf("查找失败\n");
        return NULL;
    }
    return p;
}

void OutPut(LinkList first)
{
    printf("OutPut the List:\n");
    ListNode *p=first->link;
    while(p!=NULL)
    {
        printf("%c  ",p->data);
        p=p->link;
    }
    printf("\n");
}

int main()
{
    LinkList head=NULL;
    head=CreatListR();
    ListData ch;int s;ListNode *p;
    OutPut(head);
    printf("要插入的结点值和位置分别为:\t");
    scanf("%c%d",&ch,&s);
    head=InsertList(head,ch,s);
    OutPut(head);
    printf("按值查找要查找的值为:\t");
    scanf(" %c",&ch);
    s=Findv(head,ch);
    if(s!=0)
        printf("要查找值所在的位置为:\t%d\n",s);
    printf("要查找节点的位置为:\t");
    scanf("%d",&s);
    p=Finds(head,s);
    if(p!=NULL)
        printf("要查找位置的值为:\t%c\n",p->data);
    printf("要删除节点的位置为:\t");
    scanf("%d",&s);
    head=DeleteList(head,s);
    OutPut(head);
    return 0;
}

