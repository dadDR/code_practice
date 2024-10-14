#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于按照二进制拼接后的顺序进行排序
int compare(const void *a, const void *b) {
    int num_a = *(const int *)a;
    int num_b = *(const int *)b;

    // 计算两个数的二进制长度
    int len_a = 0, len_b = 0;
    for (int i = num_a; i > 0; i >>= 1) len_a++;
    for (int i = num_b; i > 0; i >>= 1) len_b++;

    // 比较 (a << len_b) | b 和 (b << len_a) | a
    unsigned long long ab = ((unsigned long long)num_a << len_b) | num_b;
    unsigned long long ba = ((unsigned long long)num_b << len_a) | num_a;

    if (ab > ba) {
        return -1; // num_a 应排在 num_b 前面
    } else if (ab < ba) {
        return 1;  // num_b 应排在 num_a 前面
    } else {
        return 0;  // 相等
    }
}

int maxGoodNumber(int *nums, int numsSize) {
    // 对数组进行排序
    qsort(nums, numsSize, sizeof(int), compare);

    // 计算最终拼接的结果
    unsigned long long ans = 0;
    for (int i = 0; i < numsSize; i++) {
        int len = 0;
        for (int temp = nums[i]; temp > 0; temp >>= 1) {
            len++;
        }
        ans <<= len;        // 左移以腾出空间
        ans |= nums[i];     // 使用按位或拼接当前数
    }

    return (int)ans;  // 返回最终的结果，转换为 int
}

int main() {
    int nums[] = {2, 8, 16};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = maxGoodNumber(nums, numsSize);
    printf("%d\n", result);

    return 0;
}
