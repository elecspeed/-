#include "sort.h"

void selection_sort(int *array, int nums)
{
    // 选择排序
    // 内层循环后，确定第 i 大（小）的元素
    // 将其和第 i 个元素交换
    // 重复上述两步即可
    int index;
    for (int i = 0; i < nums; ++i)
    {
        // 遍历一遍，找出本次循环的最小值的下标
        index = i;
        for (int j = i + 1; j < nums; ++j)
            if (array[index] > array[j])
                index = j;
        // 交换最小值与本次循环最左边的元素。升序。
        swap(array[index], array[i]);
    }
}
void insertion_sort(int *array, int nums)
{
    // 插入排序
    // 每次外层循环后，前 i 个元素已经有序
    // 只需将第 i+1 个元素插入前面的元素中
    // （数组，所以需要挪动）
    int tmp, i, j;
    for (i = 1; i < nums; ++i)
    {
        tmp = array[i];
        for (j = i; j > 0 && array[j - 1] > tmp; --j)
            array[j] = array[j - 1];
        array[j] = tmp;
    }
}
void bubble_sort(int *array, int nums)
{
    // 冒泡排序
    // 内层循环后，最大（小）元素被移到了最右边
    // 第 nums-i 个元素就位

    // 1.
    // for (int i = 0; i < nums; ++i)
    //     for (int j = 0; j < nums - i; ++j)
    //         if (array[j] > array[j + 1])
    //             swap(array[j], array[j + 1]);

    // 2.
    bool flag;
    for (int i = 0; i < nums; ++i)
    {
        flag = true; // 假设已经有序
        for (int j = 0; j < nums - i; ++j)
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                flag = false;
            }
        if (flag)
            return;
    }
}
void quick_sort(int *array, int nums)
{
    // 递归终止
    if (nums < 2)
        return;
    // 对于小数组，快排不如插入排序
    if (nums <= 10)
    {
        insertion_sort(array, nums);
        return;
    }

    int l = 0, r = nums - 1, mid = (l + r) >> 1;
    // 比较并排序首中末，同时选取中间元
    if (array[l] > array[mid])
        swap(array[l], array[mid]);
    if (array[mid] > array[r])
        swap(array[mid], array[r]);
    if (array[l] > array[mid])
        swap(array[l], array[mid]);
    int median = array[mid];
    // 交换中间元与倒数第二个元素，有深意
    swap(array[mid], array[--r]);

    while (l < r)
    {
        while (array[++l] <= median)
            ;
        while (array[--r] >= median)
            ;
        if (l < r)
            swap(array[l], array[r]);
    }
    if (l < nums - 2)
        swap(array[nums - 2], array[l]);
    // 此时中间元才是真正意义上的“中间元”
    // 左边的比其小
    // 右边的比其大
    // 递归上述过程即可排序
    quick_sort(array, l);
    quick_sort(array + l + 1, nums - l - 1);

    // 另一种简单实现
    // if (nums < 2)
    //     return;
    // if (nums <= 8)
    // {
    //     insertion_sort(array, nums);
    //     return;
    // }
    // int l = -1, r = nums,
    //     mid = array[(l + r) >> 1]; // 直接以中心元素为中间元
    // while (l < r)
    // {
    //     while (array[++l] < mid)
    //         ;
    //     while (array[--r] > mid)
    //         ;
    //     if (l < r)
    //         swap(array[l], array[r]);
    // }
    // quick_sort(array, l);
    // quick_sort(array + l, nums - l);
}
void shell_sort(int *array, int nums)
{
    // 希尔排序
    // 对间隔 Increment 的元素进行插入排序
    // 相当于插入排序的升级版
    //
    // 插入排序对于小数组是很快的，
    // 但对于大数组，
    // 时间都花在了数组挪动上面。
    // 相比之下，
    // 希尔排序则是跳跃式地“插入”，
    // 看似循环次数变多了，
    // 其实总的“挪动”次数变少了。
    // 数组越大，希尔排序的优势越明显。
    //
    // Increment 只要先大后小，最后为 1 即可。
    //
    // > 一开始我以为 Increment 最后为 1，
    // > 不就变成插入排序了吗？
    // > 那希尔排序还不如插入排序？
    // > 后面才想明白。

    int i, j, k, Increment, tmp;
    for (i = 30; i >= 0; --i)
    {
        Increment = pow(2, i + 1) - 1;
        for (j = Increment; j < nums; ++j)
        {
            tmp = array[j];
            for (k = j;
                 k >= Increment && tmp < array[k - Increment];
                 k -= Increment)
                array[k] = array[k - Increment];
            array[k] = tmp;
        }
    }
    // Increment 的选取决定了希尔排序的时间复杂度
    // 有两种选取
    // 1.时间复杂度 O[N^(4/5)]
    //   1, 3, 7, ..., 2^k - 1
    // 2.时间复杂度 O[N^(7/6)]
    //   1, 5, 19, 41, 109,
    //   ...,
    //   9*(4^k - 2^k) + 1 或 4^i - 3*2^i + 1
    //
    // 对于 10^4 < N < 10^5，希尔排序依然表现得很好。
    // 而且编程简单，
    // 使得其成为对较大数据经常选用的算法之一
}
const int N = 100010;
int tmp[N];
void merge_sort(int *array, int nums)
{
    // 归并排序
    // 将两段已经有序的数组合并成一个临时数组。
    // 具体来说就是，
    // 将 A[] 和 B[] 中的较小元素依次拷贝到 tmp[]。
    // 因为 A[],B[] 已经有序，
    // 所以可以在线性时间内完成。
    // 最后再将 tmp[] 中的元素拷贝回来即可。
    //
    // 那 A[],B[] 不是有序的怎么办？
    // 那就先对 A[] 和 B[] 进行归并排序，
    // 递归求解。

    if (nums < 2)
        return;
    int mid = nums >> 1;
    merge_sort(array, mid);
    merge_sort(array + mid, nums - mid);

    int i = 0, l = 0, r = mid;
    while (l < mid && r < nums)
        if (array[l] <= array[r])
            tmp[i++] = array[l++];
        else
            tmp[i++] = array[r++];
    while (l < mid)
        tmp[i++] = array[l++];
    while (r < nums)
        tmp[i++] = array[r++];

    for (i = 0, l = 0; i < nums; ++i, ++l)
        array[i] = tmp[l];
    //
    // 注意临时数组不能在递归函数内。
    // 这里用的是全局范围的数组，
    // 也可以使用驱动程序，
    // 驱动程序调用归并排序，
    // 并把动态数组 tmp[] 传参进去。
}
void heap_sort(int *array, int nums);

void radix_sort(int *array, int nums);

void bucket_sort(int *array, int nums)
{
    // 桶排序
    // 要求数据只能由正整数组成，数据之间最大差值 <M。
    // 其中，M 为数组能够一次开出的最大范围。
    // 原因与算法本身有关。
    //
    // 当然了，最大差值可以 >M，数据也可以是负数，
    // 不过这需要开多个数组，
    // 并进行一些改变。
    // 对小内存的环境不友好。

    int i, j = 0;
    for (i = 0; i < nums; ++i)
        ++tmp[array[i]];
    for (i = 0; i < N && nums > 0; i++)
        while (tmp[i])
        {
            array[j++] = i;
            --tmp[i];
        }

    // 可以看出时间复杂度为 O(M + N)
    // M 为最大差值，N 为数据个数
}

void odd_even_sort(int *array, int nums);
