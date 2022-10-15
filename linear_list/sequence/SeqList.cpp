#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;
#define InitSize 10 // 默认的最大长度
typedef struct
{
    int *data;   // 指示动态分配数组的指针
    int MaxSize; // 顺序表的最大容量
    int length;  // 顺序表的当前长度
} SeqList;


void InitList(SeqList &L)
{
    // 用 molloc 函数申请一片连续的存储空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}


// 增加动态数组的长度
void Increasesize(SeqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];         // 将数据复制到新区域
    }
    L.MaxSize = L.MaxSize + len;  // 顺序表最大长度增加 len
    free(p);                      // 释放原来的内存空间
}


// 按位查找操作。获取表L中第i个位置的元素的值
ElemType GetElem(SeqList L,int i)
{
    // ToDo: 添加对数组索引合法性的判断
    return L.data[i-1];
}
/* 
L.data=(int *)malloc(Initsize*sizeof(int));
    再次理解，为何 malloc 函数返回的存储空间起始地址要转换为
    与数据元素的数据类型相对应的指针
 */


// 按值查找操作。在表L中查找具有给定关键字值的元素
//在顺序表L中查找第一个元素值等于的元素，并返回其位序
int LocateElem(SeqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1; // 数组下标为i的元素值等于e,返回其位序i+1
    return 0; // 退出循环，说明查找失败
}


int main()
{
    SeqList L;   // 声明一个顺序表
    InitList(L); // 初始化顺序表
    // L 的信息
    printf("data* = %d, MAX_SIZE = %d, length = %d\n", 
            L.data, L.MaxSize, L.length);
    // ... 往顺序表中随便插入几个元素 ...
    Increasesize(L, 5);
    // L 的信息
    printf("data* = %d, MAX_SIZE = %d, length = %d\n", 
            L.data, L.MaxSize, L.length);
    return 0;
}