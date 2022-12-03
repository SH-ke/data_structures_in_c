#include "LinkList.h"
#define SIZE 20

/* 
统计出单链表 HL 中结点的值等于给定值 X 的结点数。
int CountX(LNode* HL,ElemType x)
 */

int CountX(LNode *HL, ElemType x);

int main()
{
    LinkList L; // 声明一个指向单链表的指针
    // 初始化一个空表
    InitList(L);
    // 给单链表随机赋值
    int arr[SIZE] = { 11, 2, 52, 75, 234, 11, 10234, 54, 34, 12, 
                      11, 234, 87, 11, 542, 11, 75, 11, 21, 12 };
    for (int i = 0; i < SIZE; i++)
        ListInsert(L, i+1, arr[i]);
    
    // 打印所有的 单链表元素
    LNode *p = L->next;
    int len = Length(L); // 表中元素个数
    printf("length = %d\n", len);
    for (int i=0; i < len; i++)
    {
        printf("L[%2d] = %d\n", i+1, p->data);
        p = p->next;
    }

    // 统计链表中 值为X的节点数
    ElemType x = 11;
    printf("x = %d, counter = %d\n", x, CountX(L, x));
    
    x = 12;
    printf("x = %d, counter = %d\n", x, CountX(L, x));
    
    x = 524;
    printf("x = %d, counter = %d\n", x, CountX(L, x));

    return 0;
}

int CountX(LNode *HL, ElemType x)
{
    // 统计链表中 值为X的节点数
    int counter = 0; // 计数器
    int i;
    int len = Length(HL); // 表中元素个数
    LNode *p = HL -> next;
    for (i = 0; i < len; i++)
    {
        if (p -> data == x) counter++;
        p = p -> next;
    }
    return counter;
}
