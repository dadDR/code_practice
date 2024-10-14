#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int a , int b)
{
    int temp = a;
    a = b;
    b = temp;
    return ;
}

int main()
{
    int n = 0;
    scanf("%d" , &n);
    int m = 0;
    scanf("%d" , &m);

    int * input = (int*)malloc(sizeof(int) * n);
    int * ans = (int*)malloc(sizeof(int) * n);
    
    //接收输入数组
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d" , &(input[i]));
    }

    //进行数位置换(到N - 1 为止)
    for(int i = 0 ;  i < m ; i++)
    {
        ans[i] = input[n - m + i];
        printf("%d" , input[n - m + i]);
        printf(" ");
    }
    //进行置换（到 N - M - 1）
    for(int i = 0 ; i < n - m ; i++)
    {
       ans[m + i]  = input[i];
       printf("%d" , input[i]);
       if(i != n - m - 1)
       {
           printf(" ");
       }
       
    }

    
    
    return 0;
}



