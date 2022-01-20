#include "stdio.h"
typedef struct BTNode
{
    char data;
    struct BTNde *lchild;
    struct BTNoode *rchild;
} * BTNode;
void preorderTraverse(BTNode T)
{
    if (!T)
        return;
    printf("%c ", T->data);
    preorderTraverse(T->lchild);
    preorderTraverse(T->rchild);
}
void inorderTraverse(BTNode T)
{
    if (!T)
        return;

    inorderTraverse(T->lchild);
    printf("%c ", T->data);
    inorderTraverse(T->rchild);
}
void postorderTraverse(BTNode T)
{
    if (!T)
        return;

    postorderTraverse(T->lchild);
    postorderTraverse(T->rchild);
    printf("%c ", T->data);
}
int main()
{
    struct BTNode t1, t2, t3, t4, t5, t6;
    t1.data = 'A', t1.lchild = &t2, t1.rchild = &t3;
    t2.data = 'B', t2.lchild = &t4, t2.rchild = NULL;
    t3.data = 'D', t3.lchild = &t5, t3.rchild = &t6;
    t4.data = 'C', t4.lchild = NULL, t4.rchild = NULL;
    t5.data = 'E', t5.lchild = NULL, t5.rchild = NULL;
    t6.data = 'F', t6.lchild = NULL, t6.rchild = NULL;
    preorderTraverse(&t1);
    printf("\n");

    inorderTraverse(&t1);
    printf("\n");

    postorderTraverse(&t1);
    return 0;
}