#include "LinkedList.h"

const int N = 100;

void test1()
{
    // 头删尾删
    List lst = NULL;
    Init(&lst);
    for (int i = 0; i < N; ++i)
        push_front(lst, i);
    Display(lst);
    putchar('\n');
    // pop_buck(lst);
    // pop_buck(lst);
    // pop_buck(lst);
    // pop_front(lst);
    // pop_front(lst);
    // pop_front(lst);
    // Display(lst);

    DestroyList(lst);
}
void test2()
{
    //
}
int main()
{
    // test1();
    test2();
    return 0;
}