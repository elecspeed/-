#define _CRT_SECURE_NO_WARNINGS 1

//����һ���������� nums�������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ���
// ���������͡�
// 
// ע���������������е�һ���������֡�
// 
// [-2,1,-3,4,-1,2,1,-5,4]
// ���6
// 
// [1]
// ���1
// 
// [5, 4, -1, 7, 8]
// ���23
// 
// ��ʾ��
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 
// int maxSubArray(int* nums, int numsSize) {
//     
// }
//

//˼·һ��������١����ÿһ�ֿ�����ϵ�ֵ��ֻ�����ֵ
// ʱ�临�Ӷȣ�O(N^2);
// �ռ临�Ӷȣ�O(1);
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

//˼·���������㷨��
// ʱ�临�Ӷȣ�O(N);
// �ռ临�Ӷȣ�O(1);
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

//˼·�������Ρ�
