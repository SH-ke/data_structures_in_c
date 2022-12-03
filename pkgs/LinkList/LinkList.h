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
bool InitList(LinkList &L);

// 判断单链表是否为空（带头结点）
bool Empty(LinkList L);

// 插入操作。在表L中的第i个位置上插入指定元素e。
// 在第1个位置插插入元素e(带头结点
bool ListInsert(LinkList &L, int i, ElemType e);

//后插操作：在p结点之后插入元素e
bool InsertNextNode(LNode *p, ElemType e);

// 前插操作：在p结点之前插入元素e
// 时间复杂度 O(n)
bool InsertpriorNode(LinkList L, LNode *p, ElemType e);

// 前插操作：在p结点之前插入元素e
// 时间复杂度 O(1)
bool InsertPriorNode(LNode *p, ElemType e);

// 删除操作。删除表L中第i个位置的元素，并用e返回删除元素的值
bool ListDelete(LinkList &L, int i, ElemType &e);

// 删除指定结点p
bool DeleteNode(LNode *p);

// 销毁链表
bool Destroy(LinkList L);

// 按位查找操作。获取表L中第个位置的元素的值。
// 按位查找，返回第i个元素(带头结点)
LNode *GetElem(LinkList L, int i);

// 按值查找操作。在表L中查找具有给定关键字值的元素。
// 按值查找，找到数据域==e的结点
LNode *LocateElem(LinkList L, ElemType e);

// 求表的长度
int Length(LinkList L);