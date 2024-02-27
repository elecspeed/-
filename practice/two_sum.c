#define _CRT_SECURE_NO_WARNINGS 1

//给定一个整数数组 nums 和一个整数目标值 target，
// 请你在该数组中找出 和为目标值 target  的那两个整数，并返回它们的数组下标。
// 只会存在一个有效答案，数组中同一个元素在答案里不能重复出现。
// 你可以按任意顺序返回答案。
// 
// nums = [2,7,11,15], target = 9
// 输出[0, 1]
// 解释：因为 nums[0] + nums[1] == 9 ，返回[0, 1] 。
// 
// nums = [3, 2, 4], target = 6
// 输出[1, 2]
// 
// nums = [3, 3], target = 6
// 输出[0, 1]
// 
// 提示：
// 2 <= nums.length <= 10^4
// - 10^9 <= nums[i] <= 10^9
// - 10^9 <= target <= 10^9
//

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//
//}

//思路一：暴力。求出数组中每两个元素的和，再和 target 比较
// 时间复杂度：O(N^2)
// 空间复杂度：O(1)
//
//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//    int* index = (int*)malloc(2 * sizeof(int));
//    *returnSize = 2;
//    int sum_tmp;
//    int i, j;
//    for (i = 0; i < numsSize; ++i)
//    {
//        for (j = i + 1; j < numsSize; ++j)
//        {
//            sum_tmp = nums[i] + nums[j];
//            if (sum_tmp == target)
//            {
//                index[0] = i;
//                index[1] = j;
//            }
//        }
//    }
//
//    return index;
//}
//官方题解
//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//    for (int i = 0; i < numsSize; ++i) {
//        for (int j = i + 1; j < numsSize; ++j) {
//            if (nums[i] + nums[j] == target) {
//                int* ret = malloc(sizeof(int) * 2);
//                ret[0] = i, ret[1] = j;
//                *returnSize = 2;
//                return ret;
//            }
//        }
//    }
//    *returnSize = 0;
//    return NULL;
//}

//没想到

//思路二：哈希。
//        思路一时间复杂度较高的原因是寻找 target - x ，
//        使用哈希表，将寻找 target - x 的时间复杂度从 O(N) 降到 O(1)
// 时间复杂度：O(N)
// 空间复杂度：O(N)
//
//struct hashTable {
//    int key;
//    int val;
//    UT_hash_handle hh;
//};
//struct hashTable* hashtable;
//struct hashTable* find(int ikey) {
//    struct hashTable* tmp;
//    HASH_FIND_INT(hashtable, &ikey, tmp);
//    return tmp;
//}
//void insert(int ikey, int ival) {
//    struct hashTable* it = find(ikey);
//    if (it == NULL) {
//        struct hashTable* tmp = malloc(sizeof(struct hashTable));
//        tmp->key = ikey, tmp->val = ival;
//        HASH_ADD_INT(hashtable, key, tmp);
//    }
//    else {
//        it->val = ival;
//    }
//}
//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//    hashtable = NULL;
//    for (int i = 0; i < numsSize; i++) {
//        struct hashTable* it = find(target - nums[i]);
//        if (it != NULL) {
//            int* ret = malloc(sizeof(int) * 2);
//            ret[0] = it->val, ret[1] = i;
//            *returnSize = 2;
//            return ret;
//        }
//        insert(nums[i], i);
//    }
//    *returnSize = 0;
//    return NULL;
//}

//标签：数组、哈希表