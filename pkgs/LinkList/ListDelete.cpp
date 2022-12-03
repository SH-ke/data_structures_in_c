#include "ListDelete.h"

//删除指定结点p
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    LNode *q = p->next;      // 令q指向*p的后继结点
    p->data = p->next->data; // 和后继结点交换数据域
    p->next = q->next;       // 将*q结点从链中“断开”
    free(q);                 // 释放后继结点的存储空间
    return true;
}

// 删除操作。删除表L中第i个位置的元素，并用e返回删除元素的值
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i < 1) return false;
    LNode *p = GetElem(L, i-1); // 查找删除位置的前驱节点
    DeleteNode(p);
    return true;
}

// 销毁链表
bool Destroy(LinkList L) {
    LNode *p = L -> next;
    while (p != NULL) {
        LNode *q = p;
        p = p->next;
        free(q); // 释放节点空间
    }
    return NULL;
}
