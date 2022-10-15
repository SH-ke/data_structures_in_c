// 不带头结点的单链表
#include <stdio.h>
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


void test()
{
    LinkList L; // 声明一个指向单链表的指针
    // 初始化一个空表
    InitList(L);
    // ···后续代码···