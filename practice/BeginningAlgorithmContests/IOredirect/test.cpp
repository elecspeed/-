/*
 * 输入输出重定向
 */

// 典型的比赛代码
#include <cstdio>
#define LOCAL

int main()
{
#ifdef LOCAL
    /*
     * 如果比赛要求标准输入输出，
     * 只需在提交前删除 #define LOCAL 即可。
     * 一个更好的方法是
     * 在编译选项而不是在程序里定义 LOCAL
     */
    freopen("input.txt", "r", stdin);   // 从文件 input.txt 读
    freopen("output.txt", "w", stdout); // 从文件 output.txt 写
#endif
    const int N = 10;

    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
        // printf("%d\n", arr[i]); // 输出中间信息，用于调试
        // 对于这种在程序的最终版本不应该出现、
        // 删了又觉得可惜的代码，
        // 可以注释掉
    }
    // ...（后略）
    return 0;
}