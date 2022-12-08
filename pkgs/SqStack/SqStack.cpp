#include "SqStack.h"

// 初始化栈
void InitStack(SqStack &S)
{
    S.top = -1;   // 初始化栈顶指针
    S.length = 0; // 栈中元素个数设为 0
}

// 判断栈空
bool StackEmpty(SqStack S)
{
    if (S.top == -1) // 栈空
        return true;
    else // 不空
        return false;
}

// 新元素入栈
bool Push(SqStack &S, ElemType x)
{
    if (S.top == MaxSize - 1) // 栈满，报错
        return false;
    S.top = S.top + 1; // 指针先加1
    S.data[S.top] = x; // 新元素入栈

    /*
    // 等价写法
    S.data[++S.top] = x;
    */
    S.length++;
    return true;
}

// 出栈操作
bool Pop(SqStack &S, ElemType x)
{
    if (S.top == -1) // 栈空，报错
        return false;
    x = S.data[S.top]; // 栈顶元素先出栈
    S.top = S.top - 1; // 指针再减1

    /*
    // 等价写法
    S.data[S.top--] = x;
    */
    S.length--;
    return true;
}

// 读栈顶元素
bool GetTop(SqStack S, ElemType &x)
{
    if (S.top == -1) // 栈空，报错
        return false;
    x = S.data[S.top]; // x记录栈顶元素
    return true;
}

// 销毁栈
bool DestroyStack(SqStack &S)
{
    ElemType x;
    while (!StackEmpty(S))
        Pop(S, x);
    return true;
}