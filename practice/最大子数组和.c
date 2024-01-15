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

//思路一：暴力穷举。算出每一种可能组合的值，只留最大值
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

//思路二：联机算法。
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
