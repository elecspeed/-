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
        if (a == 0 && b == 0 && c == 0)
            break;
        double res = 1.0 * a / b;
    }
    return 0;
}