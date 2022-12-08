#include "SqStack.h"
#include <string.h>

void showStack(SqStack S)
{
    ElemType p = S.top;
    int i;
    for (i = 0; i < S.length; i++)
        printf("S[%2d] = %d\n", i, S.data[i]);
}

void testStack()
{
    SqStack S; // 声明一个顺序栈（分配空间）
    InitStack(S);
    // 后续操作
    int length = 9;
    ElemType arr[length] = {11, 2, 52, 75, 234, 87, 10234, 54, 34};
    int i;

    for (i = 0; i < length; i++)
        Push(S, arr[i]);

    showStack(S);
}
/*
假设以 I 和 O 分别表示入栈和出栈操作。栈的初态和终态均为空，
入栈和出栈的操作序列可表示为仅由 I 和 O 组成的序列，
可以操作的序列称为合法序列，否则称为非法序列。
下面所示的序列中哪些是合法的？
A.IOIIOIOO
B.IOOIOIIO
C.IIOIOIO
D.IIOOIOO
 */

bool Judge(char seq[])
{
    int length = strlen(seq);
    int i;
    ElemType x;
    SqStack S;
    InitStack(S);

    for (i = 0; i < length; i++)
    {
        if (seq[i] == 'O' && StackEmpty(S))
            return false;
        else if (seq[i] == 'O')
            Pop(S, x);
        else
            Push(S, 0);
    }
    if (StackEmpty(S))
        return true;
    else
        return false;
}

int main()
{
    testStack();

    // 判断

    char A[] = "IOIIOIOO";
    char B[] = "IOOIOIIO";
    char C[] = "IIIOIOIO";
    char D[] = "IIIOOIOO";

    Judge(A) ? printf("合法\n") : printf("非法序列\n");
    Judge(B) ? printf("合法\n") : printf("非法序列\n");
    Judge(C) ? printf("合法\n") : printf("非法序列\n");
    Judge(D) ? printf("合法\n") : printf("非法序列\n");
    return 0;
}