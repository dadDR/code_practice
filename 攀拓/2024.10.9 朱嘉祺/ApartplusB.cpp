#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    long long A = 0;
    long long B = 0;
    long long Da = 0;
    long long Db = 0;
    //接收数据
    scanf("%lld %lld %lld %lld" , &A , &Da , &B , &Db);
    //得到Pa
    long long Pa = 0;
    //遍历A
    int tempA = A;
    while(tempA != 0)
    {
        int tpa = tempA % 10;
        tempA /= 10;
        if(tpa == Da)
        {
            Pa *= 10;
            Pa += Da;
        }
    }
    //遍历B
    long long Pb = 0;
    int tempB = B;
    while(tempB != 0)
    {
        int tpb = tempB % 10;
        tempB /= 10;
        if(tpb == Db)
        {
            Pb *= 10;
            Pb += Db;
        }
    }
    printf("%lld" , Pa + Pb);
    return 0;
}

