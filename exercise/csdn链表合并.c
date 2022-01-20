#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); 
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);

    return 0;
}

struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2){
    typedef struct ListNode Node;
    Node head; // 1）设置头节点，就不用单独处理头节点了；另外用 head 保存合并结果的头指针
    Node *c = &head; // 迭代链表节点
    head.next = NULL;

    while (list1 && list2){
        if (list1->data < list2->data){
            c->next = list1;           
            list1 = list1->next;        
        }else{
            c->next = list2;
            list2 = list2->next;
        }
        c=c->next;
    }
    if (list1) c->next=list1;
    else c->next = list2;
	// head 是临时添加的头节点，head.next 才是真正的第一个节点
    return head.next;
}
struct ListNode *createlist(){
    typedef struct ListNode Node;

    Node head, *cur;
    head.next = NULL;
    cur = &head;

    scanf("%d", &head.data);
    while (-1 != head.data){
        cur->next = calloc(1, sizeof(Node));
        cur= cur->next;
        cur->data = head.data;
        scanf("%d", &head.data);
    }
    return head.next; 
}



