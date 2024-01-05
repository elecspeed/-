#define _CRT_SECURE_NO_WARNINGS 1

//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。
// 你有办法在O(n)时间内完成吗？
// 
// [3,0,1]
// 输出2
// [9, 6, 4, 2, 3, 5, 7, 0, 1]
// 输出8
// 
// int missingNumber(int* nums, int numsSize){
// 
// }
//

//思路一：把 0 到 n 的所有数加起来，再减去数组的所有项
// 时间复杂度：O(n);
// 空间复杂度：O(1);
//
int missingNumber(int* nums, int numsSize) {
    int sum = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++)
        sum += nums[i];

    return numsSize * (numsSize + 1) / 2 - sum;     //用了等差数列求和公式
}

//思路二：对数组快速排序，相邻两项相差不等于1，就是消失的数字
// 时间复杂度：O( N*logN );
// 空间复杂度：O(1);
// （略）
//

//思路三：哈希。创建一个数组，把原数组的数标记为 1。
//        遍历新数组，标记不为 0 的元素下标即为消失的数字
// 时间复杂度：O(N);
// 空间复杂度：O(N);
//
//int missingNumber(int* nums, int numsSize) {
//    int hash[10000] = { 0 };
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//        hash[nums[i]] = 1;
//
//    for (i = 0; i < numsSize + 1; i++)
//        if (hash[i] == 0)
//            return i;
//
//    return -1;
//}

//思路四：利用位运算 ^ （异或）的性质
//int missingNumber(int* nums, int numsSize) {
//    int x = 0;
//    int i = 0;
// 
//    //x 跟[0, n]异或
//    for (i = 0; i <= numsSize; i++)
//        x ^= i;
//
//    //再跟数组的每一项异或
//    for (i = 0; i < numsSize; i++)
//        x ^= nums[i];
//
//    return x;
//}
