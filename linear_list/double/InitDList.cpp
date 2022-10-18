#include "DLinkList.h"

// 初始化双链表
bool InitDLinkList(DLinklist &L)
{
    L = (DNode *)malloc(sizeof(DNode)); // 分配一个头结点
    if (L == NULL)                      // 内存不足，分配失败
        return false;
    L->prior = NULL; // 头结点的prior永远指向NULL
    L->next = NULL;  // 头结点之后暂时还没有节点
    return true;
}

// 判断双链表是否为空（带头结点）
bool Empty(DLinklist L)
{
    if (L->next = NULL)
        return true;
    else
        return false;
}

void testDLinkList()
{
    // 初始化双链表
    DLinklist L;
    InitDLinkList(L);
    // 后续代码。。。
}