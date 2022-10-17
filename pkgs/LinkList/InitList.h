#pragma once

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

// 按位查找操作。获取表L中第个位置的元素的值。
// 按位查找，返回第i个元素(带头结点)
LNode *GetElem(LinkList L, int i);

// 按值查找操作。在表L中查找具有给定关键字值的元素。
// 按值查找，找到数据域==e的结点
LNode *LocateElem(LinkList L, ElemType e);

// 求表的长度
int Length(LinkList L);