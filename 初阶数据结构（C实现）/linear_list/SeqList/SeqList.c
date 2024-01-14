#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SeqListPrint(SL* ps)
{
    int i;
    for (i = 0; i < ps->size; i++)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

void SeqListInit(SL* ps)
{
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}

void SeqListDestroy(SL* ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}

void Check_SeqList_IsFull(SL* ps)
{
    //���ռ��Ƿ���㣬���������
    if (ps->size == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        SLdatatype* tmp = (SLdatatype*)realloc(ps->a, newcapacity * sizeof(SLdatatype));
        if (!tmp)
        {
            printf("fail to realloc\n");
            exit(-1);
        }

        ps->a = tmp;
        ps->capacity = newcapacity;
    }
}

void SeqListPushBack(SL* ps, SLdatatype x)
{
    //Check_SeqList_IsFull(ps);

    //ps->a[ps->size] = x;
    //ps->size++;

    //д�� SeqListInsert ���ü���
    SeqListInsert(ps, ps->size, x);
}

void SeqListPopBack(SL* ps)
{
    //assert(ps->size > 0);
    //ps->size--;

    //д�� SeqListErase ���ü���
    SeqListErase(ps, ps->size-1);
}

void SeqListPushFront(SL* ps, SLdatatype x)
{
    //Check_SeqList_IsFull(ps);

    ////Ų������
    //int end = ps->size - 1;
    //while (end >= 0)
    //{
    //    ps->a[end + 1] = ps->a[end];
    //    end--;
    //}

    //ps->a[0] = x;
    //ps->size++;

    //д�� SeqListInsert ���ü���
    SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SL* ps)
{
    //assert(ps->size > 0);

    ////Ų������
    //int start = 0;
    //while (start < ps->size - 1)
    //{
    //    ps->a[start] = ps->a[start + 1];
    //    start++;
    //}

    //ps->size--;

    //д�� SeqListErase ���ü���
    SeqListErase(ps, 0);
}

void SeqListInsert(SL* ps, int pos, SLdatatype x)
{
    assert(pos >= 0 && pos <= ps->size);

    Check_SeqList_IsFull(ps);

    //Ų������
    int end = ps->size;
    while (end > pos)
    {
        ps->a[end] = ps->a[end - 1];
        end--;
    }

    ps->a[pos] = x;
    ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
    assert(pos >= 0 && pos < ps->size);

    int start = pos;
    while (start < ps->size - 1)
    {
        ps->a[start] = ps->a[start + 1];
        start++;
    }
    
    ps->size--;
}

int SeqListFind(SL* ps, SLdatatype x)
{
    //�ҵ������±꣬�Ҳ�������-1
    int i;
    for (i = 0; i < ps->size; i++)
        if (ps->a[i] == x)
            return i;

    return -1;
}
