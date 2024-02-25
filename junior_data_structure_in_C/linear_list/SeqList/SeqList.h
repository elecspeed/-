#define _CRT_SECURE_NO_WARNINGS 1

//#pragma once
//#define N 1000
//typedef int SLdatatype;
//
////��̬˳���
//typedef struct SeqList
//{
//    SLdatatype a[N];
//    int size;   //��ʾ�����д洢�˶��ٸ�����
//}SL;
//
////�ӿں���
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

//��̬˳���
typedef struct SeqList
{
    SLdatatype* a;
    int size;        //��ʾ�����д洢�˶��ٸ�����
    int capacity;    //��ʾ���������
}SL;


//�ӿں���
void SeqListPrint(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListInit(SL* ps);
void Check_SeqList_IsFull(SL* ps);

//��
void SeqListPushBack(SL* ps, SLdatatype x);
void SeqListPushFront(SL* ps, SLdatatype x);
void SeqListInsert(SL* ps, int pos, SLdatatype x);  //��ָ��λ���������
//ɾ
void SeqListPopFront(SL* ps);
void SeqListPopBack(SL* ps);
void SeqListErase(SL* ps, int pos);          //ɾ��ָ��λ�õ�����

//��
int SeqListFind(SL* ps, SLdatatype x);  //�ҵ������±꣬�Ҳ�������-1

