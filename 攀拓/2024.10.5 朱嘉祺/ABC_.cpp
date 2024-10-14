#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n = 0;//测试用例个数
    scanf("%d" , &n);
    for(int i = 0; i < n ; i++)
    {
        long long A = 0;
        long long B = 0;
        long long C = 0;
        //接收ABC
        scanf("%lld %lld %lld" ,  &A , &B , &C);
        if(A > C || B > C)
        {
            printf("Case #%d: true\n" , (i + 1));
            continue;
        }
        if(A + B > C)
        {
            printf("Case #%d: true\n" , (i + 1));
        }
        else
        {
            printf("Case #%d: false\n", (i + 1));
        }
    }
    return 0;
}

