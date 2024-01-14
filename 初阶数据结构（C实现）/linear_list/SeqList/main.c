#define _CRT_SECURE_NO_WARNINGS 1

//���Ա�n��������ͬ���Ե����� ����������
// ���������Ա���
// ˳�������ջ�����С��ַ����ȵ�
// 
// ���Ա����߼��������Եģ�������ṹ�ϲ�һ����
// ������ṹ�ϣ����Ա����������ʽ�ṹ����ʽ�洢
// 

//˳���
// �洢��Ԫ�������ַ���� �� �������δ洢 �����Խṹ��һ�������������ʵ��
// ����
// ˳���������顣������Ļ����ϣ���Ҫ�����ݴ�ͷ��ʼ�����洢
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
