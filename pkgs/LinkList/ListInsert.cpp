#include "ListInsert.h"

// 插入操作。在表L中的第i个位置上插入指定元素e。
// 在第1个位置插插入元素e(带头结点
bool ListInsert(LinkList &L, int i, ElemType e)
{
    // 循环找到第i-1个结点
    LNode *p = GetElem(L, i-1);
    // 将结点s连到p之后
    InsertNextNode(p, e);
    return true; // 插入成功
}

//后插操作：在p结点之后插入元素e
bool InsertNextNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) //内存分配失败
        return false;
    s->data = e; //用结点s保存数据元素e
    s->next = p->next;
    p->next = s; //将结点s连到p之后
    return true;
}

// 前插操作：在p结点之前插入元素e
// 时间复杂度 O(n)
bool InsertPriorNode(LinkList L, LNode *p, ElemType e);

// 前插操作：在p结点之前插入元素e
// 时间复杂度 O(1)
bool InsertPriorNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s = NULL) // 内存分配失败
        return false;
    s->next = p->next;
    p->next = s;       // 新结点S连到p之后
    s->data = p->data; // 将p中元素复制到s中
    p->data = e;       // p中元素覆盖为e
    return true;
}
