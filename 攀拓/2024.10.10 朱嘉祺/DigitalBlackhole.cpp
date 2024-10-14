#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpAsc(const void* a ,const void* b)
{
    return *(char *)a - *(char *)b;//如果返回正数，会把a排在b后面
    //如果返回负数，会把a排在b前面
}

int cmpDesc(const void* a ,const void* b)
{
    return *(char *)b - *(char *)a;
}



void int_to_str(int n , char* str)
{
    sprintf(str , "%04d" ,n);
}

int str_to_int(char* str)
{
    return atoi(str);
}


int main()
{
    int n;
    scanf("%d" , &n);//接收四位数字

    //先检查是否四位数字全部相等
    char* str = (char*)malloc(sizeof(char)*5);
    int_to_str(n,str);
    if (str[0] == str[1] && str[1] == str[2] && str[2] == str[3]) {
        printf("%s - %s = 0000", str, str);
        return 0;
    }
        //使用字符串的形式进行升序和降序排列
        char* astr = (char*)malloc(sizeof(char)*5);
        char* dstr = (char*)malloc(sizeof(char)*5);
    //如果不是全部相等就开始Kaperkar的常数计算
    while(n != 6174)
    {
        //将n转字符串
        int_to_str(n,astr);
        strcpy(dstr, astr);
        //进行非递增（递减或不递增也不递减）和非递减排序
        qsort(astr , 4 ,sizeof(char), cmpAsc);//递增
        qsort(dstr , 4 ,sizeof(char), cmpDesc);//递减
        //将字符串转整数
        int numAsc = str_to_int(astr);
        int numDesc = str_to_int(dstr);
        //计算差值
        n = numDesc - numAsc;
        printf("%04d - %04d = %04d\n",numAsc , numDesc , n);
        
    }
    free(astr);
    free(dstr);
    return 0;
}


