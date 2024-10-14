#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char A[1001];
    int B = 0;
    int Q[1001];
    int R = 0;
    scanf("%s %d" , A , &B);

    for(int i = 0 ; i < strlen(A) ; i++ )
    {
        R *= 10;
        R += A[i] - '0';
        Q[i] = R / B;//更新除数
        R = R % B;//更新余数
    }

    //跳过前导零，输出除数
    //注意需要留一位，否则无法输出商
int start = 0;
while(Q[start] == 0 && start < strlen(A) - 1) {
    start++;
}
    
    for(int i = start ; i < strlen(A) ; i++)
	{
		printf("%d" , Q[i]);
	}

    printf(" %d"  , R);
    return 0;
}
