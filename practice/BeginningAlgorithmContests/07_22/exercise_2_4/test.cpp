/*
 * 练习 2-4
 * 输入两个正整数 n,m（n < m < 10^6），
 * 输出 1/n^2 + 1/(n+1)^2 + ... + 1/m^2。
 * 保留 5 位小数。
 * 输入包含多组数据，
 * 结束标记为 n=m=0。
 *
 * 样例输入：
 * 2 4
 * 65536 655360
 * 0 0
 * 样例输出：
 * Case 1: 0.42361
 * Case 2: 0.00001
 */
#include <cstdio>

int main()
{
    unsigned int n, m;
    int count = 0;
    while (scanf("%u%u", &n, &m) == 2)
    {
        if (n == 0 && m == 0)
            break;

        // 转换精度
        double res = 0, mm = m;
        for (double i = n; i <= mm; i++)
        {
            res += 1.0 / (i * i);
        }
        printf("Case %d: %.5lf\n", ++count, res);
    }
    return 0;
}