#include "DLinkInsert.h"


// 在p结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL) // 非法参数
        return false;
    s->next = p->next;
    s->prior = p;
    p->next = s;
    return true;
}