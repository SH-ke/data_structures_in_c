#pragma once

// 用链式存储方式实现的栈
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct Linknode
{
    ElemType data;         // 数据域
    struct Linknode *next; // 指针域
} *LiStack;                // 栈类型定义

/* 
用链式存储方式实现的栈

两种实现方式
    带头结点
    不带头结点 (推荐)

重要基本操作
    创（初始化）
    增（进栈）
    删（出栈）
    查（获取栈顶元素）
    如何判空、判满？
 */