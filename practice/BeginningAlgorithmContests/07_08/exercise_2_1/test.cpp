/*
 * 练习 2-1
 * 输出 100~999 中的所有水仙花数。
 */

#include <cstdio>
#include <cmath>

// int main()
// {
//     // 法一
//     int a1, a2, a3;
//     for (int i = 100; i < 1000; i++)
//     {
//         a1 = i % 10;
//         a3 = i / 100;
//         a2 = (i - a1) / 10 % 10;
//         // printf("%d %d %d ", a1, a2, a3);
//         if (pow(a1, 3) + pow(a2, 3) + pow(a3, 3) == i)
//         {
//             printf("%d\n", i);
//         }
//     }
//     // 法二
//     for (int b3 = 1; b3 < 10; b3++)
//         for (int b2 = 0; b2 < 10; b2++)
//             for (int b1 = 0; b1 < 10; b1++)
//             {
//                 int res = b1 + b2 * 10 + b3 * 100;
//                 if (pow(b1, 3) + pow(b2, 3) + pow(b3, 3) == res)
//                     printf("%d\n", res);
//             }
//     return 0;
// }

/*
 * 改题：
 * 水仙花数的新定义：
 * ab = a^2 + b^2
 * abc = a^3 + b^3 + c^3
 * abcd = a^4 + b^4 + c^4 + d^4
 * ...
 * 根据水仙花数的新定义，
 * 输出所有的水仙花数。
 */

#include <vector>
using namespace std;

using ll = long long;
using ull = unsigned ll;
vector<int> vec;
int main()
{
    ull temp, sum;
    for (ull i = 10ULL; i < ULLONG_MAX; i++)
    {
        temp = i;
        sum = 0ULL;
        do
        {
            vec.push_back(temp % 10ULL);
        } while (temp /= 10ULL);
        for (int j = 0; j < vec.size(); j++)
        {
            sum += pow(vec[j], vec.size());
        }
        if (sum == i)
        {
            printf("%llu ", i);
        }
        vec.clear();
    }
    return 0;
}