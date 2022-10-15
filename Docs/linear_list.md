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
  $i=2$时，循环$n-$2次；
  $i=3$,循环$n-$3次；
  $i=n$时，循环0次
  平均循环次数为$(n-1)p+(n-2)p+\cdots+p=\frac{n(n+1)}{2}\frac{1}{n}=\frac{n-1}{2}$