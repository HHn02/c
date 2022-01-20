#include "stdio.h"
#include "stdlib.h"
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *createlinkfromtail();
struct ListNode *removeNthFromEnd(struct ListNode *head, int n);

int main()
{
    struct ListNode *head;
    int n;
    scanf("%d", &n);
    head = createlinkfromtail();
    removeNthFromEnd(head, n);
}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    int k = 0;
    struct ListNode *t = head;
    while (t)
    {
        k++;
        t = t->next;
    }
    struct ListNode *p = head, *s;
    if (k >= 2)
    {
        if (n != k)
        {
            for (int i = 0; i < k - 1 - n; i++)
            {
                p = p->next;
            }
            s = p->next;
            p->next = s->next;
            free(s);
        }
        else if (n == k)
        {
            head = head->next;
        }
        else if (n == 1)
        {
            for (int i = 0; i < k - 1 - n; i++)
            {
                p = p->next;
            }
            s = p->next;
            p->next = NULL;
            free(s);
        }
    }
    if (k == 1)
    {
        head = NULL;
    }
    return head;
}
struct ListNode *createlinkfromtail() //无头结点（尾插法）
{
    struct ListNode *head = NULL, *p, *q;
    int x;

    while (1)
    {
        scanf("%d", &x);

        if (x == -1)
            break;
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = x;
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