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

// 在p结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s);