#define _CRT_SECURE_NO_WARNINGS 1

//����һ���������� nums���������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
// 
// [1,2,3,4,5,6,7]
// 3
// ���[5,6,7,1,2,3,4]
// 
// [-1, -100, 3, 99]
// 2
// ���[3,99,-1,-100]
// 
// ��ʾ��
// 1 <= nums.length <= 105
// - 231 <= nums[i] <= 231 - 1
// 0 <= k <= 105
// 
// void rotate(int* nums, int numsSize, int k) {
//     
// }
//

//˼·һ����������ȡ���ұߵ�Ԫ�أ�ʣ�µ�����Ųһλ����ͷ���������Ԫ�ء�
//        �����˹��̡�
// ʱ�临�Ӷȣ�O(N^2);
// �ռ临�Ӷȣ�O(1);
//
//void rotate(int* nums, int numsSize, int k) {
//    assert(nums);
//    k %= numsSize;
//    while (k--)
//    {
//        int tmp = nums[numsSize - 1];
//        int j = 0;
//        for (j = numsSize - 1; j > 0; j--)
//            nums[j] = nums[j - 1];
//        nums[0] = tmp;
//    }
//}

//˼·�����Կռ任ʱ�䡣
//        �ٿ�һ������
//        ���ұ� k%numsSize ��Ԫ�طŵ����������ߣ�ʣ�µ�Ԫ�ؽ��ŷŽ�������
//        ����ٰ����е�Ԫ�طŻ�ԭ����
// ʱ�临�Ӷȣ�O(N);
// �ռ临�Ӷȣ�O(N);
//
//void rotate(int* nums, int numsSize, int k) {
//    assert(nums);
//    k %= numsSize;
//
//    int arr[100000] = { 0 };
//    int i = 0;
//    int tmp = numsSize - k;
//    for (i = 0; i < k; i++)
//        arr[i] = nums[i + tmp];
//
//    for (i = 0; i < tmp; i++)
//        arr[i + k] = nums[i];
//
//    for (i = 0; i < numsSize; i++)
//        nums[i] = arr[i];
//}
//�ٷ����
//void rotate(int* nums, int numsSize, int k) {
//    int newArr[numsSize];
//    for (int i = 0; i < numsSize; ++i) {
//        newArr[(i + k) % numsSize] = nums[i];
//    }
//    for (int i = 0; i < numsSize; ++i) {
//        nums[i] = newArr[i];
//    }
//}
//

//˼·�����Կռ任ʱ�䡣
//        ��һ�����飬�Ž�ԭ���������Ԫ�أ����򲻱䣬������
//        ��������һ����ת������飬������������Ӽ�
//        ���������ĳһλ�ÿ�ʼ��ȡ��Ӧ��Ԫ�طŻ�ԭ���鼴��
// ʱ�临�Ӷȣ�O(N);
// �ռ临�Ӷȣ�O(N);
//
//void rotate(int* nums, int numsSize, int k) {
//    assert(nums);
//    k %= numsSize;
//    
//    int* new_arr = (int*)calloc(2 * numsSize, sizeof(int));
//    if (!new_arr)
//        return;
//
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//        new_arr[i + numsSize] = new_arr[i] = nums[i];
//
//    for (i = 0; i < numsSize; i++)
//        nums[i] = new_arr[i + numsSize - k];
//
//    free(new_arr);
//    new_arr = NULL;
//}

//˼·�ģ��ҹ��ɡ�
//        ���η�ת
//        ��תǰ�� n ��Ԫ�أ���ת���� numsSize-n ��Ԫ�أ����ת����Ԫ��
//        ���򣩷�ת����Ԫ�أ���תǰ�� n ��Ԫ�أ���ת���� numsSize-n ��Ԫ��
//        ���ɵõ���ת�������
// ʱ�临�Ӷȣ�O(N);
// �ռ临�Ӷȣ�O(1);
//
//void reserve(int* nums, int numsSize)
//{
//    assert(nums);
//    int left = 0;
//    int right = numsSize - 1;
//    while (left < right)
//    {
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        left++;
//        right--;
//    }
//}
//void rotate(int* nums, int numsSize, int k) {
//    assert(nums);
//    k %= numsSize;
//
//    reserve(nums, numsSize - k);
//    reserve(nums + numsSize - k, k);
//    reserve(nums, numsSize);
//}
//�ٷ����
//void swap(int* a, int* b) {
//    int t = *a;
//    *a = *b, * b = t;
//}
//void reverse(int* nums, int start, int end) {
//    while (start < end) {
//        swap(&nums[start], &nums[end]);
//        start += 1;
//        end -= 1;
//    }
//}
//void rotate(int* nums, int numsSize, int k) {
//    k %= numsSize;
//    reverse(nums, 0, numsSize - 1);
//    reverse(nums, 0, k - 1);
//    reverse(nums, k, numsSize - 1);
//}
//



//û�뵽

//˼·�壺��״�滻����˼·���������汾
//        ����ֱ����ת�Ḳ��ԭ�������ݣ��������������пռ俪��
//        �ܲ���ֻ��һ�����������ת��
//        ��λ�� 0 ��ʼ����������Ϊ k ������Ԫ�أ�ֱ���ص�λ�� 0
//        ����������ͷβ��������һ����״���飩
//        ���̽��������ܻ���һ����Ԫ��û�н�������Ӧ�ڵ�λ��
//        �ٴ�λ��1��ʼ���ظ��ղŵĹ��̡�
//        ��ôҪ�ظ����ٴ��أ�
//        ����ɵã�Ҫ�ظ� gcd(n, k) �Σ�gcd ��ʾ���Լ����
// ʱ�临�Ӷȣ�O(N);
// �ռ临�Ӷȣ�O(1);
//
//int gcd(int a, int b) {
//    return b ? gcd(b, a % b) : a;
//}
//void swap(int* a, int* b) {
//    int t = *a;
//    *a = *b, * b = t;
//}
//void rotate(int* nums, int numsSize, int k) {
//    k = k % numsSize;
//    int count = gcd(k, numsSize);
//    for (int start = 0; start < count; ++start) {
//        int current = start;
//        int prev = nums[start];
//        do {
//            int next = (current + k) % numsSize;
//            swap(&nums[next], &prev);
//            current = next;
//        } while (start != current);
//    }
//}

//��ǩ�����顢��ѧ��˫ָ��