#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int num;//表示是哪个数字
    int value;//表示数字的数量
}numEvery;

int main()
{
    char* input = (char*)malloc(1002 * sizeof(char));
    scanf("%s",input);
    int* ans = (int*)malloc(1002 * sizeof(int));
    memset(ans , 0 , sizeof(int)*1002);
    //对字符串进行检查,记录每个字符的出现次数
    for(int i = 0; i < strlen(input) ; i++)
    {
        ans[input[i] - '0']++;
    }
    //对结果进行输出
    for(int i = 0 ; i < 1002 ; i++)
    {
        if(ans[i] != 0)
        {
            printf("%d:%d\n" , i , ans[i]);
        }
    }

    return 0;
}



