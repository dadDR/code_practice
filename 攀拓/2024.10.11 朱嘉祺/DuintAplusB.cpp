#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 将字符 '0'-'9' 转换为整数
int strToint(char cinput) {
    return cinput - '0';
}

// 字符串相加，返回结果的位数
int strPlus(char* A, char* B, int* target) {
    // 保存长度
    int lenA = strlen(A);
    int lenB = strlen(B);
    // 设置进位值
    int carryValue = 0;
    int onePlusvalue = 0;  // 一次相加后得到的总值(单独一位的)
    
    // 倒序遍历后相加
    int ai = lenA - 1;
    int bi = lenB - 1;
    int k = 0;
    
    // 遍历每一位进行相加
    while (ai >= 0 || bi >= 0 || carryValue > 0) {
        onePlusvalue = carryValue;  // 重置并加上进位
        if (ai >= 0) {
            onePlusvalue += strToint(A[ai--]);  // A 数字相加并自减索引
        }
        if (bi >= 0) {
            onePlusvalue += strToint(B[bi--]);  // B 数字相加并自减索引
        }
        target[k++] = onePlusvalue % 10;       // 将个位数存储在结果数组
        carryValue = onePlusvalue / 10;        // 更新进位值
    }
    return k;  // 返回结果数组的长度
}

int main() {
    char* A = (char*)malloc(sizeof(char) * 1002);
    char* B = (char*)malloc(sizeof(char) * 1002);
    int outputScale = 0;  // 输出结果的进制（未使用）
    
    // 输入两个大数
    scanf("%s %s %d", A, B, &outputScale);
    
    // 分配用于存储结果的数组
    int* aPlusb = (int*)malloc(sizeof(int) * 1005);
    
    // 获取相加后的结果长度
    int k = strPlus(A, B, aPlusb);
    
    // 倒序输出相加结果（从高位到低位）
    for (int i = k - 1; i >= 0; i--) {
        printf("%d", aPlusb[i]);
    }
    printf("\n");  // 换行
    return 0;
}
