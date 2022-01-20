/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
////////////////////////////归并排序
struct ListNode*merge(struct ListNode*L,struct ListNode*R);
struct ListNode*mergeout(struct ListNode*head);
struct ListNode* sortList(struct ListNode* head){
    return mergeout(head);
}

struct ListNode*mergeout(struct ListNode*head) //分成两个分支
{
    //找中点(快慢指针)
    if (!head || !head->next)
        return head;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (1)
    {
        fast = fast->next;
        if(!fast)break;
        fast = fast->next;
        if(!fast)break;
        slow = slow->next;
    }
    struct ListNode *head2 = slow->next;
    slow->next = NULL;
    struct ListNode*L=mergeout(head);
    struct ListNode*R=mergeout(head2);
    return merge(L,R);
}
struct ListNode*merge(struct ListNode*L,struct ListNode*R)  //传入左右分支，排序合并
{
    struct ListNode *head1= (struct ListNode*)malloc(sizeof(struct ListNode)),*s;
    head1->next=NULL;  
    s=head1;
    while (L && R)
    {
        if (L->val < R->val)
        {
            s->next = L;
            L = L->next;
        }
        else
        {
            s->next = R;
            R = R->next;
        }
        s = s->next;
    }
    if (L)
        s->next = L;
    else
        s->next = R;
    return head1->next;
}
