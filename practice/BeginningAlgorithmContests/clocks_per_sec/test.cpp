/*
 * 使用 clock 函数获得程序的运行时间
 */

#include <cstdio>
#include <ctime>
int main()
{
    for (int i = 0; i < 10000; i++)
        putchar(' ');

    printf("%.2f", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}