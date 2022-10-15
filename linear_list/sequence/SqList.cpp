#include <stdio.h>
typedef int ElemType;
#define MaxSize 10 // 定义最大长度
typedef struct
{
    int data[MaxSize]; // 用静态的“数组"存放数据元素
    int length;        // 顺序表的当前长度
} SqList;              // 顺序表的类型定义

// 基本操作一初始化一个顺序表
void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0;
    // 将所有数据元素设置为默认初始值
    L.length = 0;
    // 顺序表初始长度为0
}


// 插入操作。在表L中的 「第i个位置」（位序） 上插入指定元素
bool ListInsert(SqList &L, int i, int e)
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


// 按值查找操作。在表L中查找具有给定关键字值的元素
//在顺序表L中查找第一个元素值等于的元素，并返回其位序
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1; // 数组下标为i的元素值等于e,返回其位序i+1
    return 0; // 退出循环，说明查找失败
}



// 删除操作。删除表L中第i个位置的元素，并用e返回删除元素的值
bool ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length) // 判断i的范围是否有效
        return false;
    e = L.data[i - 1];                 // 将被删除的元素赋值给e
    for (int j = i; j < L.length; j++) // 将第i个位置后的元素前移
        L.data[j - 1] = L.data[j];
    L.length--; // 线性表长度减1
    return true;
}

// 按位查找操作。获取表L中第i个位置的元素的值
ElemType GetElem(SqList L,int i)
{
    // ToDo: 添加对数组索引合法性的判断
    return L.data[i-1];
}
