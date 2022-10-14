#include <stdio.h>

#define MaxSize 10 // 定义最大长度
typedef struct
{
    int data[MaxSize]; // 用静态的"数组"存放数据元素
    int length;        // 顺序表的当前长度
} SqList;              // 顺序表的类型定义


void InitList(SqList &L);
bool ListInsert(SqList &L, int i, int e);
bool ListDelete(SqList &L, int i, int &e);

int main()
{
    //  本代码请与 SqList.cpp 文件交叉编译
    //  需要 InitList() ListInsert() 函数定义
    //  gcc -fexec-charset=GBK -o main.exe SqList.cpp delete.cpp
    // 中文在Windows命令行以 GBK 编码输出
    // -fexec-charset=GBK

    SqList L;    // 声明一个顺序表
    InitList(L); // 初始化顺序表
    int length = 10;
    int arr[length] = { 11, 2, 332, 34, 656, 1234 ,1, 8, 6, 99 };
    for (int i = 0; i < MaxSize; i++)
        ListInsert(L, i, arr[i]);
    // 打印整个data数组 「删除前」
    printf("SqList L.length = %d 「删除前」\n", L.length);
    for (int i = 0; i < MaxSize; i++)
        printf("data[%d]=%d\n", i, L.data[i]+1);
    
    // 删除
    int e = -1; //用变量e把删除的元素"带回来“
    if (ListDelete(L, 3, e))
        printf("已删除第3个元素，删除元素值为=%d\n", e);
    else
        printf("位序i不合法，删除失败\n");

    // 打印整个data数组「删除后」
    printf("SqList L.length = %d 「删除后」\n", L.length);
    for (int i = 0; i < MaxSize; i++)
        printf("data[%d]=%d\n", i, L.data[i]+1);
    return 0;
}