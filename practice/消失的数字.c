#define _CRT_SECURE_NO_WARNINGS 1

//����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ��������
// ���а취��O(n)ʱ���������
// 
// [3,0,1]
// ���2
// [9, 6, 4, 2, 3, 5, 7, 0, 1]
// ���8
// 
// int missingNumber(int* nums, int numsSize){
// 
// }
//

//˼·һ���� 0 �� n �����������������ټ�ȥ�����������
// ʱ�临�Ӷȣ�O(n);
// �ռ临�Ӷȣ�O(1);
//
int missingNumber(int* nums, int numsSize) {
    int sum = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++)
        sum += nums[i];

    return numsSize * (numsSize + 1) / 2 - sum;     //���˵Ȳ�������͹�ʽ
}

//˼·�������������������������������1��������ʧ������
// ʱ�临�Ӷȣ�O( N*logN );
// �ռ临�Ӷȣ�O(1);
// ���ԣ�
//

//˼·������ϣ������һ�����飬��ԭ����������Ϊ 1��
//        ���������飬��ǲ�Ϊ 0 ��Ԫ���±꼴Ϊ��ʧ������
// ʱ�临�Ӷȣ�O(N);
// �ռ临�Ӷȣ�O(N);
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

//˼·�ģ�����λ���� ^ ����򣩵�����
//int missingNumber(int* nums, int numsSize) {
//    int x = 0;
//    int i = 0;
// 
//    //x ��[0, n]���
//    for (i = 0; i <= numsSize; i++)
//        x ^= i;
//
//    //�ٸ������ÿһ�����
//    for (i = 0; i < numsSize; i++)
//        x ^= nums[i];
//
//    return x;
//}
