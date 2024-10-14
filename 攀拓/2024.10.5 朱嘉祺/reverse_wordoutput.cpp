#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	/*
    char** strInput = (char**)malloc(sizeof(char*) * 81);
    for(int i = 0 ; i < 81 ; i++)
    {
        strInput[i] = (char*)malloc(100 * sizeof(char));
    }*/
    char strInput[81][100];

    int cntWord = 0;//单词的数量
    char temp;
    int wordLength = 0;
    while(scanf("%s" , strInput[cntWord]) != EOF)
	{
		cntWord++;
	}
	

    for(int i = cntWord - 1 ; i >= 0 ; i--)
    {
        printf("%s" , strInput[i]);
        if(i != 0)
        {
            printf(" ");
        }
    }

    
    return 0;
}




