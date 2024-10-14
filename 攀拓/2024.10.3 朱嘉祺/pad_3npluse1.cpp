#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int callatzSolve(int n)
{
    int frequent = 0;
    while(n != 1)
    {
        if(n % 2 != 0)
        {
            //不等于0代表它是奇数
            int temp = (3 * n) + 1;
            n = temp/2;
        }
        else
        {
            n/=2;
        }
        frequent++;
    }
    return frequent;
}

int main()
{
    int ans = 0;//需要的步数

    int n = 0;
    scanf("%d" , &n);
    //进行卡拉兹猜想的函数
    ans = callatzSolve(n);
    
    printf("%d" , ans);
    return 0;
}


