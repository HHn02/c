#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createlinkfromhead()      //无头结点（前插法）
{
    Node *head, *p;
    head = NULL;
    int x;
    while (1)
    {
        p = (Node *)malloc(sizeof(Node));
        scanf("%d", &x);
        if (x == -1)
            break;

        p->data = x;
        if (head == NULL)
        {
            head = p;
            p->next = NULL;
        }
        else
            p->next = head;
            head = p;
    }

    return head;
}


Node *createlinkfromhead()      //有头结点（前插法）
{
    Node*head,*p;
    int x;
   head=(Node *)malloc(sizeof(Node));
   head->next=NULL;
   while(1)
   {
       p=(Node *)malloc(sizeof(Node));
       scanf("%d",&x);
       if(x==-1)break;
       p->data=x;
       p->next=head->next;
       head->next=p;
   }
   return head;
}


struct node *createlinkfromtail()       //无头结点（尾插法）
{
    struct node *head = NULL, *p, *q;
    int x;

    while (1)
    {
        scanf("%d", &x);

        if (x == -1)
            break;
        p = (struct node *)malloc(sizeof(struct node));
        p->data=x;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
            q = p;
        }
        else
        {

            q->next = p;
            q = p;
        }
    }

    return head; //返回头指针
}


Node *createlinkfromtail() //有头结点（尾插法）
{
    Node *head, *p, *r;
    int x;
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    r=head;
    while (1)
    {
        scanf("%d", &x);
        if (x == -1)
            break;
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->next = r->next;
        r->next = p;
        r = p;
    }

    return head;
}

void printlist_wu(Node*head)
{
    Node*p;
    p=head;
    while (p)
    {
        printf("%d",p->data);
        p=p->next;
    }

}

void printlist_you(Node *head)
{
    Node *p;
    p = head->next;
    while (p)
    {
        printf("%d", p->data);
        p = p->next;
    }
}
int main()
{
    Node *head;
    head = NULL;
    // head=createlinkfromhead();
    head = createlinkfromtail();
    // printlist_wu(head);
    printlist_you(head);
}
