#define _CRT_SECURE_NO_WARNINGS 1

//#pragma once
//#define N 1000
//typedef int SLdatatype;
//
////静态顺序表
//typedef struct SeqList
//{
//    SLdatatype a[N];
//    int size;   //表示数组中存储了多少个数据
//}SL;
//
////接口函数
//void SeqListInit(SL* ps);
//void SeqListPushBack(SL* ps, SLdatatype x);
//void SeqListPopBack(SL* ps);
//void SeqListPushFront(SL* ps, SLdatatype x);
//void SeqListPopFront(SL* ps);
//// ...


#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLdatatype;

//动态顺序表
typedef struct SeqList
{
    SLdatatype* a;
    int size;        //表示数组中存储了多少个数据
    int capacity;    //表示数组的容量
}SL;


//接口函数
void SeqListPrint(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListInit(SL* ps);
void Check_SeqList_IsFull(SL* ps);

//增
void SeqListPushBack(SL* ps, SLdatatype x);
void SeqListPushFront(SL* ps, SLdatatype x);
void SeqListInsert(SL* ps, int pos, SLdatatype x);  //在指定位置添加数据
//删
void SeqListPopFront(SL* ps);
void SeqListPopBack(SL* ps);
void SeqListErase(SL* ps, int pos);          //删除指定位置的数据

//查
int SeqListFind(SL* ps, SLdatatype x);  //找到返回下标，找不到返回-1

