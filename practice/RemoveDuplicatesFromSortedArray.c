#define _CRT_SECURE_NO_WARNINGS 1

//����һ���������� nums������ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�Ρ�
// ����ɾ����������³��ȣ�Ԫ�ص����˳�򲻱�
// 
// ע�������ǳ����³��ȵĲ��֡�ϵͳֻ����³��� �� ������³��Ȳ���
// 
// [1, 1, 2]
// ��� 2���� nums = [1, 2, _]
// 
// [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
// ��� 5���� nums = [0, 1, 2, 3, 4, _]
// 
// ��ʾ��
// 1 <= nums.length <= 3 * 10^4
// -10^4 <= nums[i] <= 10^4
// nums �Ѱ����ϸ��������
// 
// int removeDuplicates(int* nums, int numsSize) {
//     
// }
//

//˼·һ��������
//        Ų�����顣
// ʱ�临�Ӷȣ�O(N^2);
// �ռ临�Ӷȣ�O(1);
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

//˼·����˫ָ�롣
//        ������ָ����ǰ��̽�⣬һ��ָ���ں����޸�
// ʱ�临�Ӷȣ�O(N);
// �ռ临�Ӷȣ�O(1);
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

//�ٷ����
//˫ָ��
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

//��ǩ�����顢˫ָ��