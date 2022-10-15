#include <stdio.h>

#define MaxSize 10 // 定义最大长度
typedef struct
{
    int data[MaxSize]; // 用静态的"数组"存放数据元素
    int length;        // 顺序表的当前长度
} SqList;              // 顺序表的类型定义

bool ListInsert_(SqList &L, int i, int e)
{
    // beta 版增加了对数组容量和插入位置的判断
    if (i < 1 || i > L.length + 1)      // 判断i的范围是否有效
        return false;
    if (L.length >= MaxSize)            // 当前存储空间已满，不能插入
        return false;
    for (int j = L.length; j >= i; j--) // 将第i个元素及之后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;                  // 在位置i处放入e
    L.length++;                         // 长度加1
    return true;
}

void InitList(SqList &L);

int main()
{
    //  本代码请与 SqList.cpp 文件交叉编译
    //  需要 InitList() 函数定义
    //  gcc -fexec-charset=GBK -o main.exe SqList.cpp insert.cpp
    // 中文在Windows命令行以 GBK 编码输出
    // -fexec-charset=GBK

    SqList L;    // 声明一个顺序表
    InitList(L); // 初始化顺序表
    // 打印整个data数组 「插入前」
    printf("SqList L.length = %d 「插入前」\n", L.length);
    for (int i = 0; i < MaxSize; i++)
        printf("data[%d]=%d\n", i, L.data[i]);
    // ...此处省略一些代码，插入几个元素
    ListInsert_(L, 1, 32);
    ListInsert_(L, 2, 10);
    ListInsert_(L, 3, 3);
    // 打印整个data数组「插入后」
    printf("SqList L.length = %d 「插入后」\n", L.length);
    for (int i = 0; i < MaxSize; i++)
        printf("data[%d]=%d\n", i, L.data[i]);
    return 0;
}