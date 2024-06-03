#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 接口类型
struct Node;
typedef struct Node Node;
typedef Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;
struct Node
{
    ElementType data;
    PtrToNode next;
};

// 接口函数
void Init(List l);
int IsEmpty(List l);
int IsLast(List l, Position p);
void Display(List l);
Position First(List l);
Position Last(List l);
void push_buck(List l, ElementType e);
void push_front(List l, ElementType e);
ElementType pop_buck(List l);
ElementType pop_front(List l);
ElementType GetFirst(List l);
ElementType GetLast(List l);
Position Find(List l, ElementType e);
Position FindPrevious(List l, ElementType e);
int Iscontained(List l, ElementType e);
void Insert(List l, Position p, ElementType e);
int Delete_by_value(List l, ElementType e);
void Delete_by_pos(List l, Position p);
void Modify(List l, Position p, ElementType new);
void sort(List l);
void MakeEmpty(List l);
void DestroyList(List l);

#endif /* LinkedList.h */