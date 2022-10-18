// 带头结点的双链表
#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct DNode
{                               // 定义双链表结点类型
    ElemType data;              // 数据域
    struct DNode *prior, *next; // 前驱和后继指针
} DNode, *DLinklist;


// 初始化双链表
bool InitDLinkList(DLinklist &L);

// 判断双链表是否为空（带头结点）
bool Empty(DLinklist L);

// 判断结点P是否为循环双链表的表尾结点
bool isTail(DLinklist L, DNode *p);