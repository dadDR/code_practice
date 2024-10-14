#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stringJduge(char*  str)
{
    int len = strlen(str);
    int p=0,t=0,left=0,mid=0,right=0;
    //先判断xPATx ?
    //遍历字符串
    for(int i = 0 ; i < len ; i++)
    {
        //判断是否有其它字符
        if(str[i] != 'A' && str[i] != 'T' && str[i] != 'P')
        {
            printf("NO \r\n");
            return ;
        }
        //判断是不是在pt的左边
        if(str[i] == 'A' && p == 0 && t == 0)
        {
            left++;
            continue;
        }
        else if(str[i] == 'P')
        {
            p++;
            continue;
        }
        else if(str[i] == 'A' && p > 0 && t == 0)
        {
            mid++;
            continue;
        }
        else if(str[i] == 'T')
        {
            t++;
            continue;
        }
        else if(str[i] == 'A' && p > 0 && t > 0)
        {
            right++;
            continue;
        }
        else
        {
            break;
        }
    }
    //判断xPATx
    if(left == right && p == 1 && mid == 1 && t == 1)
    {
        printf("YES\r\n");
        return;
    }
    else if(p==1&&t==1&&mid==1&&left==0&&right==0)
    {
        printf("YES\r\n");
        return;
    }
    else if(p==1&&t==1&&mid!=0&&left*mid==right)
    {
        printf("YES\r\n");
        return; 
    }
    else
    {
        printf("NO\r\n");
        return;
    }
    
}


int main()
{
    int n = 0;
    scanf("%d" , &n);
    char* str = (char*)malloc(101 * sizeof(char));

    while(n--)
    {
        scanf("%s" , str);
        stringJduge(str);
    }


    
    return 0;
}





