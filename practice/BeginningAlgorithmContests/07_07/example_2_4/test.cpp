/*
 * 例 2-4
 * 计算 1! + 2! + ... + n! 的末 6 位。
 * n <= 10^6
 *
 * 输入：10
 * 输出：37913
 */

// 会溢出的写法
// #include <cstdio>
// typedef long long ll;
//
// int main()
// {
//     int n;
//     scanf("%d", &n);
//
//     ll fact = 1, sum = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         fact *= i;
//         sum += fact;
//     }
//     printf("%lld", sum % 1000000);
//     return 0;
// }

/*
 * 只进行 +,-,* 运算的表达式，
 * 其结果取余，
 * 等于每次 +,-,* 后取余，
 */
#include <cstdio>
int main()
{
    const int MOD = 1e6;
    int n;
    scanf("%d", &n);

    int fact = 1, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i % MOD;
        sum = (sum + fact) % MOD;
    }
    printf("%d", sum);
    return 0;
}