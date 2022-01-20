#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct node{
    int data;
    struct node *next;
}node;
 
node* creatlink();
node * merge(node *head1, node *head2);
void destroy(node* head);
void traverse(node* head);
 
int main()
{
    node *head,*head1,*head2;
    head1=creatlink();          //创建有序链表head1，注意head1可能是空链表
    head2=creatlink();         //创建有序链表head2，注意head2也可能是空链表
    head=merge(head1,head2);   //head1和head2合并为head
    traverse(head);
    destroy(head);
}
 
//创建带头结点的有序链表
struct node* creatlink()
{
    node *head;
    int x;
    head=(node *)malloc(sizeof( node));  //创建头结点，不存放有效数据
    head->next=NULL;     
     
     
node *r=head,*p;    
    while (1)
    {
        scanf("%d",&x);
        if (x==-1)break;
        p=(node*)malloc(sizeof(node));
         
        p->data=x;
        p->next=r->next;
        r->next=p;
        r=p;
    }
  
   return head;
 }
  
//两个有序单链表head1和head2，合并为新的有序链表，并返回新链表的头指针head
struct node * merge( node *head1,  node *head2)
{
    node *head;
    head=( node *)malloc(sizeof( node));  //创建头结点
    head->next=NULL;
     
     
node *c;
    c=head;
    while (head1&&head2)
    {
        if (head1->data<head2->data)
        {
            c->next=head1;
            head1=head1->next;
        }
        else
        {
            c->next=head2;
            head2=head2->next;
        }
        c=c->next;   
    }
    if (head1)
    {
        c->next=head1;
    }
    else
        c->next=head2;
     
     
    return head;
}
//对带头结点的链表进行遍历
void traverse( node* head)
{
     
node *s;
    s=head->next;
    for (int i = 0; i < 2; i++)
    {
        s=s->next;
    }
     
    while (s!=NULL)
    {
        printf("%d ",s->data);
        s=s->next;
    }
  
}
 
//销毁链表（包括头结点） 
void destroy( node* head)
{
    struct node *p;
    while(head!=NULL)
    {
        p = head;
        head = head ->next;
        free(p);
    }
}