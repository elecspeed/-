#include "LinkedList.h"

void Init(List l)
{
    // 初始化链表，即创建表头
    l = (PtrToNode)malloc(sizeof(Node));
    if (!l)
        assert(0);
    l->data = 0;
    l->next = NULL;
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
    // 展示链表元素（应该由用户完成）
    assert(l);
    Position p = l->next;
    for (; p; p = p->next)
        printf("%d ", p->data);
}
Position First(List l)
{
    // 返回首结点地址
    assert(l);
    return l->next;
}
Position Last(List l)
{
    // 返回尾结点地址
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
    // 头插元素
    assert(l);
    Position tmp = (PtrToNode)malloc(sizeof(Node));
    if (!tmp)
        assert(0);
    tmp->data = e;
    tmp->next = l->next;
    l->next = tmp;
}
ElementType pop_buck(List l)
{
    // 尾删元素，返回被删除的元素
    assert(l);
    if (l->next == NULL)
    {
        // 如果链表只有表头，返回
        puts("pop_buck::Empty list!");
        ElementType random;
        return random;
    }
    Position p = l;
    while (p->next->next)
        p = p->next;
    ElementType ret = p->next->data;
    free(p->next);
    p->next = NULL;
    return ret;
}
ElementType pop_front(List l)
{
    // 头删元素，返回被删除的元素
    assert(l);
    if (l->next == NULL)
    {
        // 如果链表只有表头，返回
        puts("pop_front::Empty list!");
        ElementType random;
        return random;
    }
    Position tmp = l->next;
    ElementType ret = tmp->data;
    l->next = tmp->next;
    free(tmp);
    return ret;
}
ElementType GetFirst(List l)
{
    // 返回首元素
    assert(l);
    return l->next->data;
}
ElementType GetLast(List l)
{
    // 返回尾元素
    assert(l);
    Position p = Last(l);
    return p->data;
}
Position Find(List l, ElementType e)
{
    // 查找元素
    // 找到返回地址，找不到返回 NULL
    assert(l);
    Position p = l->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}
Position FindPrevious(List l, ElementType e)
{
    // 查找元素
    // 找到返回前一个元素的地址，找不到返回 NULL
    assert(l);
    Position p = l;
    while (p->next && p->next->data != e)
        p = p->next;
    return p->next == NULL ? NULL : p;
}
int Iscontained(List l, ElementType e)
{
    // 检查 e 是否在链表内
    // 在返回真，不在返回假
    assert(l);
    if (Find(l, e) != NULL)
        return 1;
    return 0;
}
void Insert(List l, Position p, ElementType e)
{
    // 插入元素（在位置 p 后插入）
    // 使用：
    // Insert(lst, Find(lst,e1), e2)
    // Insert(lst, FindPrevious(lst,e1), e2)
    //
    assert(l);
    if (p == NULL)
    {
        // 为什么会 p == NULL
        // 1.用户直接传参，可能仅仅想添加元素而已
        // 2.使用了 Find()，想在某个元素后插入元素，但没找到。
        //   可能是由于用户想排序。
        //
        // 我选择头插，然后提醒
        push_front(l, e);
        puts("Insert::the argument p to Insert() is NULL."
             "push_front(1, e) has been called.");
        getchar();
        return;
    }
    Position tmp = (PtrToNode)malloc(sizeof(Node));
    if (!tmp)
        assert(0);
    tmp->data = e;
    tmp->next = p->next;
    p->next = tmp;
}
int Delete_by_value(List l, ElementType e)
{
    // 删除元素 e
    // 删除成功返回真，删除失败返回假
    assert(l);
    Position tmp, p = FindPrevious(l, e);
    if (p)
    {
        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
        return 1;
    }
    return 0;
}
void Delete_by_pos(List l, Position p)
{
    // 删除位置 p 处的结点，返回被删除的元素
    // 这个函数感觉很鸡肋
    assert(l);
    if (p == NULL)
    {
        // 位置 p 不存在
        puts("Delete_by_pos::"
             "the argument p to Delete_by_pos() is NULL.");
        return;
    }
    Position tmp = l;
    while (tmp->next && tmp->next != p)
        tmp = tmp->next;
    if (!tmp->next)
    {
        // 位置 p 不存在于链表中
        puts("Delete_by_pos::"
             "the argument p to Delete_by_pos() does not exist in list.");
        return;
    }
    tmp->next = p->next;
    free(p);
}
void Modify(List l, Position p, ElementType new)
{
    // 修改元素
    // 使用：
    // Modify(lst, Find(lst,e1), e2)
    // Modify(lst, Last(lst), e)
    //
    assert(l);
    if (!p)
    {
        // 位置 p 不存在
        puts("Modify::the argument p to Modify() is NULL.");
        return;
    }
    p->data = new;
}
void sort(List l);
void MakeEmpty(List l)
{
    // 清空链表，保留表头
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
void DestroyList(List l)
{
    // 彻底删除链表（包括表头）
    assert(l);
    MakeEmpty(l);
    free(l);
    l = NULL;
}
