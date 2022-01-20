/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *c1 = l1, *c2 = l2, *head, *r, *p;
    int carry = 0;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    r = head;
    int sum = 0;
    while (c1 && c2)
    {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        sum = c1->val + c2->val + carry > 9 ? (c1->val + c2->val + carry) % 10 : c1->val + c2->val + carry;
        p->val = sum;
        p->next = r->next;
        r->next = p;
        r = p;
        carry = c1->val + c2->val+carry > 9 ? 1 : 0;
        c1 = c1->next;
        c2 = c2->next;
    }

    if (carry == 1 && c1 == NULL && c2 == NULL)
    {
        struct ListNode *p3;
        p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
        p3->val = 1;
        p3->next = r->next;
        r->next = p3;
        r = p3;
    }
    struct ListNode *p1;
    if (c1 || c2)
    {
        struct ListNode *s;
        s = c1 == NULL ? c2 : c1;
        while (s)
        {
            p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
            sum = s->val + carry > 9 ? (s->val + carry) % 10 : s->val + carry;
            p1->val = sum;
            p1->next = r->next;
            r->next = p1;
            r = p1;
            carry = s->val+carry > 9 ? 1 : 0;
            s=s->next;
        }
        if (carry == 1)
        {
            struct ListNode *p2;
            p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
            p2->val = 1;
            p2->next = r->next;
            r->next = p2;
            r = p2;
        }
    }

    return head->next;
}
// @lc code=end
