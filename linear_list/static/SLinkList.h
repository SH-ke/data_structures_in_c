typedef int ElemType;
#define MaxSize 10
// 静态链表的最大长度
typedef struct
{ // 静态链表结构类型的定义
    ElemType data; // 存储数据元素
    int next; // 下一个元素的数组下标
} SLinkList[MaxSize];