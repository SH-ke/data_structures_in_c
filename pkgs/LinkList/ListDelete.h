#pragma once
#include "InitList.h"

//删除指定结点p
bool DeleteNode(LNode *p);

// 删除操作。删除表L中第i个位置的元素，并用e返回删除元素的值
bool ListDelete(LinkList &L, int i, ElemType &e);