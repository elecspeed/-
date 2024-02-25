#define _CRT_SECURE_NO_WARNINGS 1

//时间复杂度和空间复杂度
//复杂度练习


//衡量一个算法的好坏有两个标准，分别是时间复杂度和空间复杂度
// 简单来讲
// 时间复杂度衡量程序运行的快慢
// 空间复杂度衡量程序运行需要的内存空间大小
// 
// 在计算机发展早期，硬件的存储能力十分有限，对空间复杂度的要求更高
// 而今天计算机的存储容量已经达到很高的水平，对时间复杂度的要求更高


//时间复杂度
// 算法的时间复杂度是一个函数，是算法中基本操作的执行次数
// 
// 因为同一个算法在不同的硬件环境下，运行的时间是有差异的
// 不能用运行时间来算时间复杂度
// 
// 那怎么搞？
// 其实一个程序运行的时间，等于执行所有语句需要的时间
// 如果假设每条语句执行时间相同
// 把执行一条语句所花费的时间看作单位1，那么执行n条语句需要时间n
// 
// 好了，回到主题
// 算法的时间复杂度是一个函数，是算法中基本操作的执行次数
// 那么，找到某条基本语句某个基本操作，和，问题规模N之间的数学表达式，
// 就算出了该算法的时间复杂度
// 
// 算时间复杂度，即算基本操作的执行次数
// 

//void Func1(int N)
//{
//    int count = 0;
//    int i, j;
//    i = j = 0;
//    for (i = 0; i < N; i++)
//        for (j = 0; j < N; j++)
//            ++count;
//
//    for (i = 0; i < 2 * N; i++)
//        ++count;
//
//    for (i = 0; i < 10; i++)
//        ++count;
//    printf("%d", count);
//}

//函数Func1的打印结果 N*N + 2*N + 10
//Func1的时间复杂度为 F(N) = N*N + 2*N + 10 + 其他（创建变量，判断循环条件等等所花的时间）

//实际计算时间复杂度时，只要 N 的高次方，可以忽略低次方（影响不大）
// 所以Func1的时间复杂度为 N^2
// 用大O表示法：O(N^2)
//
// 大O表示法甚至把 N 的高次方的系数也忽略（也许是为了方便，也许是趋于∞时等价）
// 如果时间复杂度是 3*N^2 + 1
// 用大O表示法：O(N^2)
// 
// 虽然都是 O(N^2)，但实际运行速度还是有差距的。
// 



//void Func2(int N, int M)
//{
//    int count = 0;
//    int i = 0;
//    for (i = 0; i < N; i++)
//        ++count;
//    for (i = 0; i < M; i++)
//        ++count;
//}
//
// O(M + N)
//如果知道 M 和 N 的关系：
// 1.M 远大于 N，则为 O(M)
// 2.M 远小于 N，则为 O(N)
// 3.M 和 N 差不多大，则为 O(M) 或 O(N)
//

//库函数strchr的时间复杂度？
// O(N)
// 
// 未知长度的数组，其长度考虑成一个 N 或 M （考虑成变量）
// 有些算法的时间复杂度存在最好，最坏和平均情况
// %99的情况取最坏情况
// 
// strchr的时间复杂度最好是 O(1)，平均是 O(N)，最坏是 O(N)
// 所以strchr的时间复杂度是 O(N)
//

//void Fun3(int N)
//{
//    int count = 0;
//    int i = 0;
//    for (i = 0; i < 100; i++)
//        ++count;
//}
//O(1)

//冒泡排序的时间复杂度？
// N*(N-1)/2，即O(N^2)
//

//BinarySearch的时间复杂度？
// 最好 O(1)
// 最坏 N / 2 / 2 / ... = 1
// 假设操作了 X 次，除了 X 个 2，
// 那么 N = 2^X，于是 X = log N / log 2;
// 于是 O(log N)
//

//递归实现阶乘的时间复杂度？
//long long Fac(size_t N)
//{
//    if (0 == N)
//        return 1;
//
//    return F(N - 1) * N;
//}
// O(N)
// 递归算法的时间复杂度：递归次数 * 函数本身的时间复杂度
//

//递归实现斐波那契数列的时间复杂度？
//long long Fib(size_t N)
//{
//    if (N < 3)
//        return 1;
//
//    return Fib(N - 1) + Fib(N - 2);
//}
//O(2^N)
// 实际时间复杂度 2^0 + 2^1 + 2^2 +...+ 2^(N - 1) - X
// X 为后面缺的一部分递归调用
//



//空间复杂度
// 也是一个函数表达式，计算的是运行时 额外 需要的存储空间的大小
// 也用大O表示法

//BubbleSort 的空间复杂度？
// O(1)
// 额外需要的空间只有循环变量
//
    
//递归实现阶乘的空间复杂度？
// O(N)
// 递归算法的空间复杂度：递归深度 * 函数本身的空间复杂度
//

//递归实现斐波那契数列的空间复杂度？
// O(N)
// 空间可以重复利用，不累计的
// 时间一去不复返，累计的
// 所以
// 递归算法的空间复杂度：递归深度 * 函数本身的空间复杂度
//



//当一道算法题有多种思路时，用大O表示法估计每个方法的时间和空间消耗
// 不写代码就知道大概需要的时间和空间
// 便是大O表示法的妙处所在
//
