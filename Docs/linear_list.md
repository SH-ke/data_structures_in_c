# 线性表笔记

## 顺序表

### 插入操作

代码实现

```c
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
```

**时间复杂度分析**：

1. 最好情况：$O(1)$
  新元素插入到表尾，不需要移动元素 $i=n+1$,循环0次：

2. 最坏情况： $O(n)$
  新元素插入到表头，需要将原有的个元素全都向后移动$i=1$,循环n次

3. 平均情况：$O(n)$
  假设新元素插入到任何一个位置的概率相同，即$i=1,2,3,\cdots$,$length+1$的概率都是$p=\frac{1}{n+1}$
  $i=1$时,循环$n$次；
  $i=2$时，循环$n-1$次；
  $i=3$,循环$n-2$次；
  $i=n+1$时，循环0次
  平均循环次数为$np+(n-1)p+(n-2)p+\cdots+p=\frac{n(n+1)}{2}\frac{1}{n+1}=\frac{n}{2}$

### 删除操作

代码实现

```c
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
```

**时间复杂度分析**：

1. 最好情况：$O(1)$
  删除表尾元素，不需要移动元素； $i=n+1$,循环0次
2. 最坏情况： $O(n)$
  删除表头元素，需要将后续的$n-1$元素全都向后移动；$i=1$ ，循环$n-1$次

3. 平均情况：$O(n)$
  假设新元素删除任何一个位置的概率相同，即$i=1,2,3,\cdots$,$length+1$的概率都是$p=\frac{1}{n}$
  $i=1$时,循环$n-1$次；
  $i=2$时，循环$n-2$次；
  $i=3$,循环$n-3$次；
  $i=n$时，循环0次
  平均循环次数为$(n-1)p+(n-2)p+\cdots+p=\frac{n(n-1)}{2}\frac{1}{n}=\frac{n-1}{2}$

### 查找操作「按位」

代码实现

```c++
// 按位查找操作。获取表L中第i个位置的元素的值
ElemType GetElem(SqList L,int i)
{
    // ToDo: 添加对数组索引合法性的判断
    return L.data[i-1];
}
```

**时间复杂度**： $O(1)$
由于顺序表的各个数据元素在内存中连续存放，因此可以根据起始地址和数据元素大小立即找到第$i$个元素一一“随机存取”特性。

### 查找操作「按值」

代码实现

```c++
// 按值查找操作。在表L中查找具有给定关键字值的元素
//在顺序表L中查找第一个元素值等于的元素，并返回其位序
int LocateElem(SeqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1; // 数组下标为i的元素值等于e,返回其位序i+1
    return 0; // 退出循环，说明查找失败
}
```

**时间复杂度分析**：

1. 最好情况：$O(1)$
  目标元素在表头，循环1次
2. 最坏情况： $O(n)$
  目标元素在表位，循环$n$次

3. 平均情况：$O(n)$
  假设目标元素出现在任何一个位置的概率相同，即$i=1,2,3,\cdots$,$length+1$的概率都是$p=\frac{1}{n}$
  $i=1$时,循环$1$次；
  $i=2$时，循环$2$次；
  $i=n$时，循环$n$次
  平均循环次数为$1\cdot \frac{1}{n}+2\cdot \frac{1}{n}+\cdots+n\cdot \frac{1}{n}=\frac{n(n+1)}{2}\frac{1}{n}=\frac{n+1}{2}$

## 单链表

顺序表的特点

**优点**：可随机存取，存储密度高
**缺点**：要求大片连续空间，改变容量不方便

单链表的特点

**优点**：不要求大片连续空间，改变容量方便
**缺点**：不可随机存取，要耗费一定空间存放指针

### typedef 关键字

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

### 定义数据结构

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

### 插入操作

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

### 删除操作

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
