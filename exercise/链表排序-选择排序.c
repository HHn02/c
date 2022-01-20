#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void sort(struct node *head); //采用选择排序法思想，对结点数据进行交换处理
void destroy(struct node *head);
struct node *creatlink();
void traverse(struct node *head);

int main()
{
    struct node *head;
    head = creatlink(); //用尾插法创建链表head,注意head可能是空链表
    sort(head);
    traverse(head);
    destroy(head);
}

void sort(struct node *head)
{
    struct node *p, *q, *s;
    int t;
    for (p = head->next; p != NULL; p = p->next)
    {
        
        for (q = p->next; q != NULL; q = q->next)
        {
            
            if (q->data < p->data)
            {
               
                t = s->data;
                s->data = p->data;
                p->data = t;
            }
        }
    }
}

struct node *creatlink()
{
    struct node *head, *r, *p;
    int x;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    r = head; // head->next先置空，r再指向head
    while (1)
    {
        scanf("%d", &x);
        if (x == -1)
            break;
        p = (struct node *)malloc(sizeof(struct node));
        p->data = x;
        p->next = r->next;
        r->next = p;
        r = p;
    }

    return head;
}

void traverse(struct node *head)
{
    struct node *p;
    p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void destroy(struct node *head)
{
    struct node *p;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        free(p);
    }
}
