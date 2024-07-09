#define _CRT_SECURE_NO_WARNINGS 1

//����һ���������� nums ��һ������Ŀ��ֵ target��
// �����ڸ��������ҳ� ��ΪĿ��ֵ target  �����������������������ǵ������±ꡣ
// ֻ�����һ����Ч�𰸣�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
// ����԰�����˳�򷵻ش𰸡�
// 
// nums = [2,7,11,15], target = 9
// ���[0, 1]
// ���ͣ���Ϊ nums[0] + nums[1] == 9 ������[0, 1] ��
// 
// nums = [3, 2, 4], target = 6
// ���[1, 2]
// 
// nums = [3, 3], target = 6
// ���[0, 1]
// 
// ��ʾ��
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

//˼·һ�����������������ÿ����Ԫ�صĺͣ��ٺ� target �Ƚ�
// ʱ�临�Ӷȣ�O(N^2)
// �ռ临�Ӷȣ�O(1)
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
//�ٷ����
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

//û�뵽

//˼·������ϣ��
//        ˼·һʱ�临�ӶȽϸߵ�ԭ����Ѱ�� target - x ��
//        ʹ�ù�ϣ����Ѱ�� target - x ��ʱ�临�Ӷȴ� O(N) ���� O(1)
// ʱ�临�Ӷȣ�O(N)
// �ռ临�Ӷȣ�O(N)
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

//��ǩ�����顢��ϣ��