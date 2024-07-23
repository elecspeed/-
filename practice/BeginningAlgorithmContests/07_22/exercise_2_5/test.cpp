/*
 * 练习 2-5
 * 输入正整数 a,b,c，输出 a/b 的小数形式，
 * 精确到小数点后 c 位。
 * a,b <= 10^6  c <= 100
 *
 * 输入包含多组数据，结束标记为 a=b=c=0
 *
 * 样例输入：
 * 1 6 4
 * 0 0 0
 * 样例输出：
 * Case 1: 0.1667
 */
#include <cstdio>

int main()
{
    int a, b, c, count = 0;
    while (scanf("%d%d%d", &a, &b, &c) == 3)
    {
        // 结束标记
        if (a == 0 && b == 0 && c == 0)
            break;
        // 输出格式
        printf("Case %d: ", ++count);

        // 算法（模拟除法过程）
        printf("%d.", a / b);
        a %= b;
        for (int i = 0; i < c - 1; i++)
        {
            a *= 10;
            printf("%d", a / b);
            a %= b;
        }
        // 判断小数点后 c+1 位要不要进 1
        a *= 10;
        int lastDigit = a / b; // 精确度的最后一位
        a %= b;
        a *= 10;
        if (a / b < 5)
            // 四舍
            printf("%d\n", lastDigit);
        else
            // 五入
            printf("%d\n", lastDigit + 1);
    }
    return 0;
}