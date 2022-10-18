// 带头结点的循环单链表
#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct LNode
{                       // 定义单链表结点类型
    ElemType data;      // 每个节点存放一个数据元素
    struct LNode *next; // 指针指向下一个节点
} LNode, *LinkList;


// 初始化一个循环单链表
bool InitList(LinkList &L);

// 判断循环单链表是否为空
bool Empty(LinkList L);

// 判断结点p是否为循环单链表的表尾结点
bool isTail(LinkList L, LNode *p);