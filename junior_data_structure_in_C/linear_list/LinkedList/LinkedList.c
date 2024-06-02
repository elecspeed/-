#include "LinkedList.h"

void Init(List l)
{
    // 初始化链表，即创建表头
    assert(l);
    l = (PtrToNode)malloc(sizeof(Node));
    if (!l)
        assert(0);
    l->data = 0;
    l->next = NULL;
}
void MakeEmpty(List l)
{
}
int IsEmpty(List l)
{
    // 检查链表是否是空的
    // 是返回真，不是返回假
    assert(l);
    return l->next == NULL;
}
int IsLast(List l, Position p)
{
    // 检查当前地址是否是链表末尾
    // 是返回真，不是返回假
    assert(p && l);
    return p->next == NULL;
}
void Display(List l)
{
    assert(l);
    for (Position p = l->next; p; p = p->next)
        printf("%d ", p->data);
}
Position First(List l)
{
    assert(l);
    return l->next;
}
Position Last(List l)
{
    assert(l);
    Position p = l;
    for (; p->next; p = p->next)
        ;
    return p;
}
void push_buck(List l, ElementType e)
{
    // 尾插元素
    assert(l);
    Position p, tmp = (PtrToNode)malloc(sizeof(Node));
    if (!tmp)
        assert(0);
    tmp->data = e;
    tmp->next = NULL;
    p = Last(l);
    p->next = tmp;
}
void push_front(List l, ElementType e)
{
}
ElementType pop_buck(List l);
ElementType pop_front(List l);
ElementType GetFirst(List l);
ElementType GetLast(List l);
Position Find(List l, ElementType e)
{
    assert(l);
    Position p = l->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}
Position FindPrevious(List l, ElementType e)
{
    assert(l);
    Position p = l;
    while (p->next && p->next->data != e)
        p = p->next;
    return p;
}
int Iscontained(List l, ElementType e);

void Insert(List l, Position p, ElementType e)
{
    // 插入元素（在位置 p 后插入）
    assert(l && p);
    Position tmp = (PtrToNode)malloc(sizeof(Node));
    if (!tmp)
        assert(0);
    tmp->data = e;
    tmp->next = p->next;
    p->next = tmp;
}
int Delete_by_value(List l, ElementType e)
{
    assert(l);
    Position tmp, p = FindPrevious(l, e);
    if (!IsLast(l, p))
    {
        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }
}
ElementType Delete_by_pos(List l, Position p);

void Modify(List l, Position p, ElementType e)
{
    // 修改元素
    assert(p && l);
    if (!IsLast(l, p))
        p->data = e;
}
void sort(List l);
void DeleteList(List l)
{
    // 删除链表，保留表头
    assert(l);
    PtrToNode p, tmp;
    p = l->next;
    while (p != NULL)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}
ElementType retrieve(List l, Position p);
