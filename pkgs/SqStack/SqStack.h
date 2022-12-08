#pragma once

// 顺序栈
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

#define MaxSize 10 // 定义栈中元素的最大个数
typedef struct
{
    ElemType data[MaxSize]; // 静态数组存放栈中元素
    int top, length;        // 栈顶指针、栈中元素的长度
} SqStack;

// 初始化栈
void InitStack(SqStack &S);

// 判断栈空
bool StackEmpty(SqStack S);

// 新元素入栈
bool Push(SqStack &S, ElemType x);

// 出栈操作
bool Pop(SqStack &S, ElemType x);

// 读栈顶元素
bool GetTop(SqStack S, ElemType &x);

// 销毁栈
bool DestroyStack(SqStack &S);

/*
设计栈的结构时，S.top = 存在 -1 和 0 两种情况
此处取 -1
两种不同的方法影响栈的 初始化、判断栈空
 */