#include "LinkList.h"
#define SIZE 20

int main()
{
    LinkList L; // 声明一个指向单链表的指针
    // 初始化一个空表
    InitList(L);
    // ···后续代码···
    int arr[SIZE] = { 11, 2, 52, 75, 234, 87, 10234, 54, 34 };
    for (int i = 0; i < SIZE; i++)
        ListInsert(L, i+1, arr[i]);
    
    printf("length = %d\n", Length(L));
    // 打印所有的 单链表元素
    LNode *p = L->next;
    for (int i=0; i < Length(L); i++)
    {
        printf("L[%2d] = %d\n", i+1, p->data);
        p = p->next;
    }

    return 0;
}