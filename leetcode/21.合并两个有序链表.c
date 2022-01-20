/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

   struct ListNode *head,*c;
    
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->next=NULL;
    c=head;
    while (l1&&l2)
    {
        if (l1->val<l2->val)
        {   
            c->next=l1;
            l1=l1->next;
        }
        else
        {
            c->next=l2;
            l2=l2->next;
        } 
        c=c->next;
    }
    if (l1)
    {
        c->next=l1;
    }
    else   
        c->next=l2;

    return head->next;
}
// @lc code=end

