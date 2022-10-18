#include "DLinkDelete.h"

void DestoryList(DLinklist &L)
{ // 循环释放各个数据结点
    while (L->next != NULL)
        DeleteNextDNode(L);
    free(L);  // 释放头结点
    L = NULL; // 头指针指向WULL
}


// 删除p结点的后继结点
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;
    DNode *q = p->next; // 找到p的后继结点q
    p->next = q->next;
    q->next->prior = p;
    free(q); // 释放结点空间
    return true;
}