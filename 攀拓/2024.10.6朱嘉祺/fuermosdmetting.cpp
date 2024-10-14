#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // 给四个字符串开辟空间
    char* str1 = (char*)malloc(sizeof(char) * 61);
    char* str2 = (char*)malloc(sizeof(char) * 61);
    char* str3 = (char*)malloc(sizeof(char) * 61);
    char* str4 = (char*)malloc(sizeof(char) * 61);

    // 接收四个字符串
    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%s", str3);
    scanf("%s", str4);

    // 定义星期数组
    char* days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    
    int foundDay = 0; // 是否已经找到星期的标志
    int firstMinlen = strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2);

    // 进行前两个字符串的检查
    for (int i = 0; i < firstMinlen; i++)
    {
        // 寻找星期部分
        if (!foundDay && str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G')
        {
            printf("%s ", days[str1[i] - 'A']);
            foundDay = 1;
            continue;
        }

        // 寻找小时部分（第2对相同字符）
        if (foundDay && str1[i] == str2[i])
        {
            if ('0' <= str1[i] && str1[i] <= '9')
            {
                printf("%02d:", str1[i] - '0');
                break;
            }
            else if ('A' <= str1[i] && str1[i] <= 'N')
            {
                printf("%02d:", str1[i] - 'A' + 10);
                break;
            }
        }
    }

    int secondMinlen = strlen(str3) < strlen(str4) ? strlen(str3) : strlen(str4);

    // 进行后两个字符串的检查
    for (int i = 0; i < secondMinlen; i++)
    {
        if (str3[i] == str4[i] && ((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z')))
        {
            printf("%02d", i);
            break;
        }
    }

    // 释放内存
    free(str1);
    free(str2);
    free(str3);
    free(str4);

    return 0;
}
