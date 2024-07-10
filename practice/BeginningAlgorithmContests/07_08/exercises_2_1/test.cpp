/*
 * 练习 2-1
 * 输出 100~999 中的所有水仙花数。
 */

#include <cstdio>
#include <cmath>

int main()
{
    // 法一
    int a1, a2, a3;
    for (int i = 100; i < 1000; i++)
    {
        a1 = i % 10;
        a3 = i / 100;
        a2 = (i - a1) / 10 % 10;
        // printf("%d %d %d ", a1, a2, a3);
        if (pow(a1, 3) + pow(a2, 3) + pow(a3, 3) == i)
        {
            printf("%d\n", i);
        }
    }
    // 法二
    for (int b3 = 1; b3 < 10; b3++)
        for (int b2 = 0; b2 < 10; b2++)
            for (int b1 = 0; b1 < 10; b1++)
            {
                int res = b1 + b2 * 10 + b3 * 100;
                if (pow(b1, 3) + pow(b2, 3) + pow(b3, 3) == res)
                    printf("%d\n", res);
            }
    return 0;
}

// 如果题目改为输出所有水仙花数？