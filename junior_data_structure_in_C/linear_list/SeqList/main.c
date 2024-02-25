#define _CRT_SECURE_NO_WARNINGS 1

//线性表：n个具有相同特性的数据 的有限序列
// 常见的线性表有
// 顺序表、链表、栈、队列、字符串等等
// 
// 线性表在逻辑上是线性的，在物理结构上不一定。
// 在物理结构上，线性表常以数组或链式结构的形式存储
// 

//顺序表
// 存储单元的物理地址连续 且 数据依次存储 的线性结构。一般情况下用数组实现
// 或者
// 顺序表就是数组。在数组的基础上，还要求数据从头开始连续存储
//

#include "SeqList.h"

void TestSeqList1()
{
    SL s1;
    SeqListInit(&s1);

    SeqListPushBack(&s1, 1);
    SeqListPushBack(&s1, 2);
    SeqListPushBack(&s1, 3);
    SeqListPushBack(&s1, 4);
    SeqListPushBack(&s1, 5);

    SeqListPrint(&s1);

    SeqListPopBack(&s1);
    SeqListPopBack(&s1);

    SeqListPrint(&s1);

    SeqListDestroy(&s1);

}

void TestSeqList2()
{
    SL s1;
    SeqListInit(&s1);

    SeqListPushBack(&s1, 1);
    SeqListPushBack(&s1, 2);
    SeqListPushBack(&s1, 3);
    SeqListPrint(&s1);

    SeqListPushFront(&s1, 10);
    SeqListPushFront(&s1, 20);
    SeqListPushFront(&s1, 30);
    SeqListPrint(&s1);

    SeqListPopFront(&s1);
    SeqListPopFront(&s1);
    SeqListPrint(&s1);

    SeqListDestroy(&s1);
}

void TestSeqList3()
{
    SL s1;
    SeqListInit(&s1);

    SeqListPushBack(&s1, 1);
    SeqListPushBack(&s1, 2);
    SeqListPushBack(&s1, 3);
    SeqListPushBack(&s1, 4);
    SeqListPushBack(&s1, 5);
    SeqListPrint(&s1);

    SeqListInsert(&s1, 1, 10);
    SeqListInsert(&s1, 3, 20);
    SeqListInsert(&s1, 5, 30);
    SeqListInsert(&s1, 7, 40);
    SeqListPrint(&s1);

    SeqListErase(&s1, 2);
    SeqListErase(&s1, 4);
    SeqListErase(&s1, 6);
    SeqListPrint(&s1);

    SeqListDestroy(&s1);
}

void TestSeqList4()
{
    SL s1;
    SeqListInit(&s1);

    SeqListPushBack(&s1, 1);
    SeqListPushBack(&s1, 2);
    SeqListPushBack(&s1, 3);
    SeqListPushBack(&s1, 4);
    SeqListPushBack(&s1, 5);
    SeqListPrint(&s1);

    int pos = SeqListFind(&s1, 2);
    if (pos != -1)
    {
        SeqListInsert(&s1, pos, 10);
    }
    SeqListPrint(&s1);

    pos = SeqListFind(&s1, 4);
    if (pos != -1)
    {
        SeqListInsert(&s1, pos, 20);
    }
    SeqListPrint(&s1);

    SeqListErase(&s1, 3);
    SeqListErase(&s1, 3);
    SeqListErase(&s1, 3);
    SeqListPrint(&s1);


    SeqListDestroy(&s1);
}

int main()
{
    //TestSeqList1();
    //TestSeqList2();
    //TestSeqList3();
    TestSeqList4();

    return 0;
}
