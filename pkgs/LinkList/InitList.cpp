#include "InitList.h"

// 初始化一个单链表（带头结点）
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
    if (L == NULL)                      // 内存不足，分配失败
        return false;
    L->next = NULL; // 头结点之后暂时还没有节点
    return true;
}

// 判断单链表是否为空（带头结点）
bool Empty(LinkList L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}

// 按位查找操作。获取表L中第个位置的元素的值。
// 按位查找，返回第i个元素(带头结点)
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p;
    // 指针p指向当前扫描到的结点
    int j = 0;
    // 当前p指向的是第几个结点
    p = L;
    // L指向头结点，头结点是第0个结点（不存数据
    while (p != NULL & j < i)
    {
        // 循环找到第i个结点
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找操作。在表L中查找具有给定关键字值的元素。
// 按值查找，找到数据域==e的结点
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    // 从第1个结点开始查找数据域为e的结点
    while (p != NULL & p->data != e)
        p = p->next;
    return p; // 找到后返回该结点指针，否则返回WULL
}

// 求表的长度
int Length(LinkList L)
{
    int len = 0;
    // 统计表长
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}