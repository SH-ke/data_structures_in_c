#pragma once
#include "InitList.h"

//后插操作：在p结点之后插入元素e
bool InsertNextNode(LNode *p, ElemType e);

// 前插操作：在p结点之前插入元素e
// 时间复杂度 O(n)
bool InsertPriorNode(LinkList L, LNode *p, ElemType e);

// 前插操作：在p结点之前插入元素e
// 时间复杂度 O(1)
bool InsertPriorNode(LNode *p, ElemType e);

// 插入操作。在表L中的第i个位置上插入指定元素e。
// 在第1个位置插插入元素e(带头结点
bool ListInsert(LinkList &L, int i, ElemType e);