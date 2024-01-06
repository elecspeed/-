#define _CRT_SECURE_NO_WARNINGS 1

//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
// 
// [1,2,3,4,5,6,7]
// 3
// 输出[5,6,7,1,2,3,4]
// 
// [-1, -100, 3, 99]
// 2
// 输出[3,99,-1,-100]
// 
// 提示：
// 1 <= nums.length <= 105
// - 231 <= nums[i] <= 231 - 1
// 0 <= k <= 105
// 
// void rotate(int* nums, int numsSize, int k) {
//     
// }
//

//思路一：暴力。提取最右边的元素，剩下的往右挪一位。再头插提出来的元素。
//        遍历此过程。
// 时间复杂度：O(N^2);
// 空间复杂度：O(1);
//
//void rotate(int* nums, int numsSize, int k) {
//    assert(nums);
//    k %= numsSize;
//    while (k--)
//    {
//        int tmp = nums[numsSize - 1];
//        int j = 0;
//        for (j = numsSize - 1; j > 0; j--)
//            nums[j] = nums[j - 1];
//        nums[0] = tmp;
//    }
//}

//思路二：以空间换时间。
//        再开一块数组
//        把右边 k%numsSize 个元素放到新数组的左边，剩下的元素接着放进新数组
//        最后再把所有的元素放回原数组
// 时间复杂度：O(N);
// 空间复杂度：O(N);
//
//void rotate(int* nums, int numsSize, int k) {
//    assert(nums);
//    k %= numsSize;
//
//    int arr[100000] = { 0 };
//    int i = 0;
//    int tmp = numsSize - k;
//    for (i = 0; i < k; i++)
//        arr[i] = nums[i + tmp];
//
//    for (i = 0; i < tmp; i++)
//        arr[i + k] = nums[i];
//
//    for (i = 0; i < numsSize; i++)
//        nums[i] = arr[i];
//}
//官方题解
//void rotate(int* nums, int numsSize, int k) {
//    int newArr[numsSize];
//    for (int i = 0; i < numsSize; ++i) {
//        newArr[(i + k) % numsSize] = nums[i];
//    }
//    for (int i = 0; i < numsSize; ++i) {
//        nums[i] = newArr[i];
//    }
//}
//

//思路三：以空间换时间。
//        开一块数组，放进原数组的所有元素，排序不变，放两次
//        发现任意一个轮转后的数组，都是新数组的子集
//        从新数组的某一位置开始，取相应个元素放回原数组即可
// 时间复杂度：O(N);
// 空间复杂度：O(N);
//
//void rotate(int* nums, int numsSize, int k) {
//    assert(nums);
//    k %= numsSize;
//    
//    int* new_arr = (int*)calloc(2 * numsSize, sizeof(int));
//    if (!new_arr)
//        return;
//
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//        new_arr[i + numsSize] = new_arr[i] = nums[i];
//
//    for (i = 0; i < numsSize; i++)
//        nums[i] = new_arr[i + numsSize - k];
//
//    free(new_arr);
//    new_arr = NULL;
//}

//思路四：找规律。
//        三次翻转
//        翻转前面 n 个元素，翻转后面 numsSize-n 个元素，最后翻转所有元素
//        （或）翻转所有元素，翻转前面 n 个元素，翻转后面 numsSize-n 个元素
//        即可得到轮转后的数组
// 时间复杂度：O(N);
// 空间复杂度：O(1);
//
//void reserve(int* nums, int numsSize)
//{
//    assert(nums);
//    int left = 0;
//    int right = numsSize - 1;
//    while (left < right)
//    {
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        left++;
//        right--;
//    }
//}
//void rotate(int* nums, int numsSize, int k) {
//    assert(nums);
//    k %= numsSize;
//
//    reserve(nums, numsSize - k);
//    reserve(nums + numsSize - k, k);
//    reserve(nums, numsSize);
//}
//官方题解
//void swap(int* a, int* b) {
//    int t = *a;
//    *a = *b, * b = t;
//}
//void reverse(int* nums, int start, int end) {
//    while (start < end) {
//        swap(&nums[start], &nums[end]);
//        start += 1;
//        end -= 1;
//    }
//}
//void rotate(int* nums, int numsSize, int k) {
//    k %= numsSize;
//    reverse(nums, 0, numsSize - 1);
//    reverse(nums, 0, k - 1);
//    reverse(nums, k, numsSize - 1);
//}
//



//没想到

//思路五：环状替换。是思路二的升级版本
//        由于直接轮转会覆盖原来的数据，用数组来存又有空间开销
//        能不能只用一个变量完成轮转？
//        从位置 0 开始，交换距离为 k 的两个元素，直到回到位置 0
//        （假设数组头尾相连，是一个环状数组）
//        过程结束，可能会有一部分元素没有交换到其应在的位置
//        再从位置1开始，重复刚才的过程。
//        那么要重复多少次呢？
//        计算可得，要重复 gcd(n, k) 次（gcd 表示最大公约数）
// 时间复杂度：O(N);
// 空间复杂度：O(1);
//
//int gcd(int a, int b) {
//    return b ? gcd(b, a % b) : a;
//}
//void swap(int* a, int* b) {
//    int t = *a;
//    *a = *b, * b = t;
//}
//void rotate(int* nums, int numsSize, int k) {
//    k = k % numsSize;
//    int count = gcd(k, numsSize);
//    for (int start = 0; start < count; ++start) {
//        int current = start;
//        int prev = nums[start];
//        do {
//            int next = (current + k) % numsSize;
//            swap(&nums[next], &prev);
//            current = next;
//        } while (start != current);
//    }
//}

//标签：数组、数学、双指针