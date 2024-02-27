#define _CRT_SECURE_NO_WARNINGS 1

//给你一个有序数组 nums，请你原地删除重复出现的元素，使每个元素只出现一次。
// 返回删除后数组的新长度，元素的相对顺序不变
// 
// 注：不考虑超出新长度的部分。系统只检查新长度 和 数组的新长度部分
// 
// [1, 1, 2]
// 输出 2，且 nums = [1, 2, _]
// 
// [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
// 输出 5，且 nums = [0, 1, 2, 3, 4, _]
// 
// 提示：
// 1 <= nums.length <= 3 * 10^4
// -10^4 <= nums[i] <= 10^4
// nums 已按非严格递增排列
// 
// int removeDuplicates(int* nums, int numsSize) {
//     
// }
//

//思路一：暴力。
//        挪动数组。
// 时间复杂度：O(N^2);
// 空间复杂度：O(1);
//
//int removeDuplicates(int* nums, int numsSize) {
//    int newlen = 1;
//    int i, j;
//    for (i = 1; i < numsSize; i++)
//    {
//        if (nums[i - 1] == nums[i])
//        {
//            for (j = i; j < numsSize - 1; j++)
//                nums[j] = nums[j + 1];
//            i--;
//            numsSize--;
//        }
//        else
//            newlen++;
//    }
//    return newlen;
//}

//思路二：双指针。
//        用两个指针在前面探测，一个指针在后面修改
// 时间复杂度：O(N);
// 空间复杂度：O(1);
// 
//int removeDuplicates(int* nums, int numsSize) {
//    int i, j, index;
//    i = j = 0;
//    index = 1;
//    while (j < numsSize - 1)
//    {
//        j++;
//        while (nums[i] == nums[j] && j < numsSize - 1) j++;
//        if(nums[i] != nums[j])
//           nums[index++] = nums[j];
//        i = j;
//    }
//
//    return index;
//}

//官方题解
//双指针
//int removeDuplicates(int* nums, int numsSize) {
//    if (numsSize == 0) {
//        return 0;
//    }
//    int fast = 1, slow = 1;
//    while (fast < numsSize) {
//        if (nums[fast] != nums[fast - 1]) {
//            nums[slow] = nums[fast];
//            ++slow;
//        }
//        ++fast;
//    }
//    return slow;
//}

//标签：数组、双指针