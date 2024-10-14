#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//判断一个数是否是素数
int primeJudge(int num)
{
    for(int i = 2 ; i <= sqrt(num) ; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}




int main()
{
    int m = 0;
    int n = 0;
    int count = 0;//每行数字量的计数器
    int isspaceFlag = 0;//判断是否需要加空格
    int primeCnt = 1;//素数计数
    int nowPrime = 2;//第一个素数是2
    
    scanf("%d %d" ,  &m , &n);

    //素数：定义：除了一以外能被自身整除的数
    //先找到第m个素数
    if(primeCnt != m)
    {
        //顺延素数
        while(primeCnt != m)
        {
            nowPrime++;
            //判断是否是素数
            if(primeJudge(nowPrime))
            {
                primeCnt++;
            }
        }
    }
    //先输出m
    printf("%d" , nowPrime);
    count++;
    isspaceFlag = 1;
    //找到之后从m到n进行输出
   while(primeCnt < n)
   {
       nowPrime++;
       //判断是否是素数
       if(primeJudge(nowPrime))
       {
           primeCnt++;
           if(isspaceFlag == 0)
           {
               isspaceFlag = 1;
               printf("%d" , nowPrime);
           }
           else
           {
               printf(" %d" , nowPrime);
           }
           
           count++;
           if(count == 10)
           {
               count = 0;
               printf("\n");
               isspaceFlag = 0;
           }
       }
   }
    
    return 0;
}


