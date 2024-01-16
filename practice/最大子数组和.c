#define _CRT_SECURE_NO_WARNINGS 1

//给你一个整数数组 nums，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），
// 返回其最大和。
// 
// 注：子数组是数组中的一个连续部分。
// 
// [-2,1,-3,4,-1,2,1,-5,4]
// 输出6
// 
// [1]
// 输出1
// 
// [5, 4, -1, 7, 8]
// 输出23
// 
// 提示：
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 
// int maxSubArray(int* nums, int numsSize) {
//     
// }
//

//思路一：暴力穷举。
//        算出每一种可能组合的值，只留最大值
// 时间复杂度：O(N^2);
// 空间复杂度：O(1);
//
//int maxSubArray(int* nums, int numsSize) {
//    int max, this;
//    int i, j;
//    max = INT_MIN;
//    for (i = 0; i < numsSize; i++)
//    {
//        this = 0;
//        for (j = i; j < numsSize; j++)
//        {
//            this += nums[j];
//
//            if (max < this)
//                max = this;
//        }
//    }
//    return max;
//}

//思路二：联机算法。（也算动态规划，网上有叫联机算法的，也有叫动态规划的）
// 时间复杂度：O(N);
// 空间复杂度：O(1);
//
//int maxSubArray(int* nums, int numsSize) {
//    int max, this;
//    max = INT_MIN;
//    this = 0;
//
//    int i;
//    for (i = 0; i < numsSize; i++)
//    {
//        this += nums[i];
//        if (max < this)
//            max = this;
//        if (this < 0)
//            this = 0;
//    }
//    return max;
//}

//思路三：分治。
//        最大子数组要么在左半边，要么在右半边，要么在中间
//        左右的好办，中间的要
//        左半边包含边界往右，右半边包含边界往左，两组循环分别求最大值
//        最后相加即可
// 时间复杂度：O(N*logN);
// 空间复杂度：O(logN);
//
//int max3(int a, int b, int c)
//{
//    int max = a > b ? a : b;
//    return max > c ? max : c;
//}
//int maxSubArray(int* nums, int numsSize) {
//    /*    base case    */
//    if (numsSize <= 0)
//        return 0;
//    else if (numsSize == 1)
//        return nums[0];
//
//    /*  left max subarr and right  */
//    int mid_ = numsSize / 2;
//    int max_right = maxSubArray(nums, mid_);
//    int max_left = maxSubArray(nums + numsSize / 2, numsSize - mid_);
//
//    /*   mid max subarr   */
//    int max_mid;
//    int mid_l_this, mid_r_this;
//    int mid_l_max, mid_r_max;
//    max_mid = mid_l_max = mid_r_max = INT_MIN;
//    mid_l_this = mid_r_this = 0;
//
//    int i;
//    for (i = mid_ - 1; i >= 0; i--)
//    {
//        mid_l_this += nums[i];
//        if (mid_l_max < mid_l_this)
//            mid_l_max = mid_l_this;
//    }
//
//    for (i = mid_; i < numsSize; i++)
//    {
//        mid_r_this += nums[i];
//        if (mid_r_max < mid_r_this)
//            mid_r_max = mid_r_this;
//    }
//    max_mid = mid_l_max + mid_r_max;
//
//    return max3(max_right, max_left, max_mid);
//}
<<<<<<< HEAD

//官方题解
//一：动态规划
// 
//int maxSubArray(int* nums, int numsSize) {
//    int pre = 0, maxAns = nums[0];
//    for (int i = 0; i < numsSize; i++) {
//        pre = fmax(pre + nums[i], nums[i]);
//        maxAns = fmax(maxAns, pre);
//    }
//    return maxAns;
//}

//二：分治
//    类似于「线段树求解最长公共上升子序列问题」的 pushUp 操作
//    （目前还不是很懂）
// 
//struct Status {
//    int lSum, rSum, mSum, iSum;
//};
//
//struct Status pushUp(struct Status l, struct Status r) {
//    int iSum = l.iSum + r.iSum;
//    int lSum = fmax(l.lSum, l.iSum + r.lSum);
//    int rSum = fmax(r.rSum, r.iSum + l.rSum);
//    int mSum = fmax(fmax(l.mSum, r.mSum), l.rSum + r.lSum);
//    return (struct Status) { lSum, rSum, mSum, iSum };
//};
//
//struct Status get(int* a, int l, int r) {
//    if (l == r) {
//        return (struct Status) { a[l], a[l], a[l], a[l] };
//    }
//    int m = (l + r) >> 1;
//    struct Status lSub = get(a, l, m);
//    struct Status rSub = get(a, m + 1, r);
//    return pushUp(lSub, rSub);
//}
//
//int maxSubArray(int* nums, int numsSize) {
//    return get(nums, 0, numsSize - 1).mSum;
//}

=======
>>>>>>> 0aac05dea1964a31c1a61263770f8a26748c64fa
