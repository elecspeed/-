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

//˼·һ��������١�
//        ���ÿһ�ֿ�����ϵ�ֵ��ֻ�����ֵ
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
//        ���������Ҫô�����ߣ�Ҫô���Ұ�ߣ�Ҫô���м�
//        ���ҵĺð죬�м��Ҫ
//        ���߰����߽����ң��Ұ�߰����߽���������ѭ���ֱ������ֵ
//        �����Ӽ���
// ʱ�临�Ӷȣ�O(N*logN);
// �ռ临�Ӷȣ�O(logN);
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
