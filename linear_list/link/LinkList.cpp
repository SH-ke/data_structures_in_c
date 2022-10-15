// 带头结点的单链表
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode // 定义单链表结点类型
{
    ElemType data;      // 每个节点存放一个数据元素
    struct LNode *next; // 指针指向下一个节点
} LNode, *LinkList;

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

// 插入操作。在表L中的第i个位置上插入指定元素e。
// 在第1个位置插插入元素e(带头结点
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    LNode *p;  // 指针p指向当前扫描到的结点
    int j = 0; // 当前p指向的是第几个结点
    p = L;     // L指向头结点，头结点是第0个结点（不存数据）
    while (p != NULL & j < i - 1)
    { // 循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if (p == NULL) // i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; // 将结点s连到p之后
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
bool InsertpriorNode(LinkList L, LNode *p, ElemType e);

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

// 删除操作。删除表L中第i个位置的元素，并用e返回删除元素的值
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i < 1)
        return false;
    LNode *p;  // 指针p指向当前扫描到的结点
    int j = 0; // 当前p指向的是第几个结点
    p = L;     // L指向头结点，头结点是第0个结点（不存数据）
    while (p != NULL & j < i - 1)
    { // 循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if (p == NULL) // i值不合法
        return false;
    if (p->next == NULL) // 第i-1个结点之后已无其他结点
        return false;
    LNode *q = p->next; // 令q指向被删除结点
    e = q->data;        // 用e返回元素的值
    p->next = q->next;  // 将*q结点从链中“断开”
    free(q);            // 释放结点的存储空间
    return true;        // 删除成功
}

//删除指定结点p
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    LNode *q = p->next;      //令q指向*p的后继结点
    p->data = p->next->data; //和后继结点交换数据域
    p->next = q->next;       //将*q结点从链中“断开”
    free(q);                 //释放后继结点的存储空间
    return true;
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

void test()
{
    LinkList L; // 声明一个指向单链表的指针
    // 初始化一个空表
    InitList(L);
    // ···后续代码···
}