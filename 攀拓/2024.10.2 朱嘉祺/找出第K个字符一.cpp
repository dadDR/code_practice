#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* kth_Slove(char* group , int len)
{
	printf("group origin is %s \r\n" , group);
	printf("len is %d\r\n" ,len);
    for(int i = 0 ; i < len ; i++)
    {
        char temp = group[i];
        group[i + len] = temp + 1;
    }
    group[len*2] = '\0';
    printf("group after is %s \r\n" , group);
    
    return group;
}



char kthCharacter(int k) {
    char* charGroup = (char*)malloc(513 * sizeof(char));
    charGroup[0] = 'a';
    charGroup[1] = '\0';
    //在最初的状态上，字符串是"a"
    //直接进行打表就行？
    //可以知道，每次生成后字符数量的规律：2^n ， n为生成的次数
    //因为k < 500  ， 故最多生成 2^9 = 512
    int originLen = 1;
    for(int i  = 0 ; i < 9 ; i++)
    {
    	
        charGroup = kth_Slove(charGroup , originLen);
        originLen *= 2;
    }
	for(int i  = 0 ; i < strlen(charGroup) ; i++ )
	{
		printf("%c" , charGroup[i]);
	}
	printf("\r\n");
    return charGroup[k - 1];
}

int main()
{
	char ans;
	int k = 0;
	scanf("%d" , &k);
	ans = kthCharacter(k);
	printf("ans is %c" , ans);
	return 0;
}