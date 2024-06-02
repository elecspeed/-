#include "LinkedList.h"

const int N = 1000;
void test1()
{
    List lst;
    PtrToNode head;
    init(lst);
    for (int i = 0; i < N; i++)
    {
        Insert(i, lst, Find(i - 1, lst));
    }
}
int main()
{
    test1();
    return 0;
}