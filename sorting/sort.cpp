#include <iostream>
using namespace std;

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
    if (nums <= 8)
    {
        insertion_sort(array, nums);
        return;
    }

    int l = 0, r = nums - 1, mid = (l + r) >> 1;
    // 比较并排序首中末，同时选取中间元
    if (array[l] > array[mid])
        swap(array[l], array[mid]);
    if (array[mid] > array[r])
        swap(array[l], array[mid]);
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
}

void shell_sort(int *array, int nums);

void merge_sort(int *array, int nums);

void heap_sort(int *array, int nums);

void radix_sort(int *array, int nums);

void bucket_sort(int *array, int nums);

void odd_even_sort(int *array, int nums);