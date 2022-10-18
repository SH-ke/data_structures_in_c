#include "InitDList.h"

// 初始化空的循环双链表
bool InitDLinkList(DLinklist &L)
{
    L = (DNode *)malloc(sizeof(DNode)); // 分配一个头结点
    if (L == NULL)                      // 内存不足，分配失败
        return false;
    L->prior = L; // 头结点的prior指向头结点
    L->next = L;  // 头结点的next指向头结点
    return true;
}

// 判断循环双链表是否为空
bool Empty(DLinklist L)
{
    if (L->next = L)
        return true;
    else
        return false;
}


// 判断结点P是否为循环双链表的表尾结点
bool isTail(DLinklist L, DNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}

void testDLinkList()
{
    // 初始化循环双链表
    DLinklist L;
    InitDLinkList(L);
    // ···后续代码···
}