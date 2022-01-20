//迭代
struct ListNode* reverseList(struct ListNode* head){
        struct ListNode *cur=NULL,*pre=head;
        struct ListNode *temp=NULL;
        while(pre)
        {
            temp=pre->next;
            pre->next=cur;
            cur=pre;
            pre=temp;
        }
        return cur;
}
 //递归
struct ListNode* reverseList(struct ListNode* head){
   
    if(!head||!head->next)
        return head;
    struct ListNode *newhead=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}