#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

    int n = 0;
    int count = 0;//记录数字位数的变量
    scanf("%d" , &n);
    int* cntGroup = (int*)malloc(100 * sizeof(int));
    if(cntGroup != NULL)
	{
		memset(cntGroup, 0, 100 * sizeof(int));
	}
    //char* ans = (char*)malloc(1000*sizeof(char));
    //取出各位数然后进行处理
    while(n)
    {
        cntGroup[count++] = n % 10;
        n /= 10;
        //count++;
    }
    //位数数组倒序进行输出
    
    //输出B
    if(count >= 3)
	{
		    int bCnt = cntGroup[count-1];
    count--;
    while(bCnt--)
    {
        printf("B");
    }
	}

	if(count >= 2)
	{
		    //输出S
    int sCnt = cntGroup[count-1];
    count--;
    while(sCnt--)
    {
        printf("S");
    }
	}

	if(count >= 1)
	{
		    //输出个位
    int gCnt = cntGroup[count-1];
    count--;
    char gOut = '1';
    while(gCnt--)
    {
        printf("%c" , gOut);
        gOut++;
    }
	}

    
    return 0;
}


