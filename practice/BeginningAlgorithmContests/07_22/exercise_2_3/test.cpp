/*
 * 练习 2-3
 * 输入正整数 n <= 20，
 * 输出一个 n 层的倒三角形。
 * 例：
 * n = 4
 * #######
 *  #####
 *   ###
 *    #
 */
#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            putchar(' ');
        for (int j = 0; j < (n - i) * 2 - 1; j++)
            putchar('#');
        putchar('\n');
    }
    return 0;
}