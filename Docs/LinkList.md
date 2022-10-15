# 单链表笔记

顺序表的特点

**优点**：可随机存取，存储密度高
**缺点**：要求大片连续空间，改变容量不方便

单链表的特点

**优点**：不要求大片连续空间，改变容量方便
**缺点**：不可随机存取，要耗费一定空间存放指针

## typedef 关键字

使用方法演示

```c++
// typedef<数据类型><别名>
typedef int zhengshu;
typedef int *zhengshuzhizhen;
int x = 1;
int *p;

// 以上代码「等价于」
zhengshu x = 1;
zhengshuzhizhen p;
```

## 定义数据结构

分别使用 LNode, LinkList 两个关键字来表示单个节点和整个单链表（头指针/头节点）

```c++
typedef int ElemType;
typedef struct LNode    //定义单链表结点类型
{
    ElemType data;      //每个节点存放一个数据元素
    struct LNode *next; //指针指向下一个节点
} LNode, *LinkList;

// 以上代码的等价详细写法如下
struct LNode            //定义单链表结点类型
{
    ElemType data;      //每个节点存放一个数据元素
    struct LNode *next; //指针指向下一个节点
};

typedef struct LNode LNode;
typedef struct LNode *LinkList;
// 要表示一个单链表时，只需声明一个头指针L, 指向单链表的第一个结点
LNode *L;   //声明一个指向单链表第一个结点的指针
LinkList L; //声明一个指向单链表第一个结点的指针。代码可读性更强
```

## 插入操作

代码实现

```c
// 插入操作。在表L中的第i个位置上插入指定元素e。
// 在第1个位置插插入元素e(带头结点)
// 平均时间复杂度 O(n)
bool ListInsert(LinkList &L, int i, ElemType e);

//后插操作：在p结点之后插入元素e
// 时间复杂度 O(1)
bool InsertNextNode(LNode *p, ElemType e);

// 前插操作：在p结点之前插入元素e
// 时间复杂度 O(n)
bool InsertpriorNode(LinkList L, LNode *p, ElemType e);

// 前插操作：在p结点之前插入元素e
// 时间复杂度 O(1)
bool InsertPriorNode(LNode *p, ElemType e);
```

## 删除操作

代码实现

```c++
// 删除操作。删除表L中第i个位置的元素，并用e返回删除元素的值
// 最好时间复杂度 O(1)  最坏、平均时间复杂度 O(n)
bool ListDelete(LinkList &L, int i, ElemType &e);

//删除指定结点p 存在bug
// 时间复杂度 O(1)
bool DeleteNode(LNode *p);

// 时间复杂度 O(n)
bool DeleteNode(LinkList &L, LNode *p);
```

## 查找操作

代码实现，及其时间复杂度

```c++
// 按位查找操作。获取表L中第个位置的元素的值。
// 按位查找，返回第i个元素(带头结点)
// 平均时间复杂度 O(n)
LNode *GetElem(LinkList L, int i);

// 按值查找操作。在表L中查找具有给定关键字值的元素。
// 按值查找，找到数据域==e的结点
// 平均时间复杂度 O(n)
LNode *LocateElem(LinkList L, ElemType e);
```

## 封装调用

在实现了单链表的查找操作之后，结合之前的「后插操作」、「指定节点删除」，可以发现 `bool ListInsert();` 函数可以调用封装的函数，精简代码。

给出修改之后的`bool ListInsert();` 函数：

```cpp
//后插操作：在p结点之后插入元素e
bool InsertNextNode(LNode *p, ElemType e);

// 按位查找，返回第i个元素(带头结点)
LNode *GetElem(LinkList L, int i);

//在第i个位置插插入元素e(带头结点)
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;

    LNode *p = GetElem(L, i - 1); // 找到第i-1个结点

    return InsertNextNode(p, e);
}
```

对`bool ListDelete();` 函数如法炮制

```c++
//删除指定结点p
bool DeleteNode(LNode *p);

// 按位查找操作。获取表L中第个位置的元素的值。
LNode *GetElem(LinkList L, int i);

bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i < 1)
        return false;

    LNode *p = GetElem(L, 1 - 1); //找到第i-1个结点
    if (p == NULL)                // i值不合法
        return false;
    if (p->next == NULL) // 第i-1个结点之后已无其他结点
        return false;

    return DeleteNode(p);
}
```

## 计算表长

代码实现及其时间复杂度

```c++
// 求表的长度
// 时间复杂度 O(n)
int Length(LinkList L)
{
    int len = 0;
    // 统计表长
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
```
