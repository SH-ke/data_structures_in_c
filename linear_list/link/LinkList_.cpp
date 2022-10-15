// 不带头结点的单链表
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode    // 定义单链表结点类型
{
    ElemType data;      // 每个节点存放一个数据元素
    struct LNode *next; // 指针指向下一个节点
} LNode, *LinkList;

// 初始化一个空的单链表
bool InitList(LinkList &L)
{
    L = NULL; // 空表，暂时还没有任何结点
    return true;
}


// 判断单链表是否为空（带头结点）
bool Empty(LinkList L)
{
    if (L == NULL)
        return true;
    else
        return false;
}


//  插入操作。在表L中的第i个位置上插入指定元素e。
//  在第1个位置插插入元素e(带头结点)
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    if (i == 1)
    { // 插入第1个结点的操作与其他结点操作不同
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s; // 头指针指向新结点
        return true;
    }
    LNode *p;  // 指针p指向当前扫描到的结点
    int j = 1; // 当前p指向的是第几个结点
    p = L;     // p指向第1个结点（注意：不是头结点）
    while (p != NULL && j < i - 1)
    { // 循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if (p == NULL) // i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true; // 插入成功
}

void test()
{
    LinkList L; // 声明一个指向单链表的指针
    // 初始化一个空表
    InitList(L);
    // ···后续代码···