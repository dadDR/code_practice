int countOfSubstrings(char* word, int k) {
    //直接进行遍历？
    /*
    int consonant = 0;
    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;
    for(int i = 0 ; i < strlen(word) ; i++)
    {
        if(word[i] == 'a')
        {
            a++;
        }
        else if(word[i] == 'e')
        {
            e++;
        }
        else if(word[i] == 'i')
        {
            i++;
        }
        else if(word[i] == 'o')
        {
            o++;
        }
        else if(word[i] == 'u')
        {
            u++;
        }
        else
        {
            consonant++;
            if(consonant > k)
            {
                return 0;
            }
        }
    }*/
    //可以模拟一个队列
    //并非直接进行遍历，需要使用滑动窗口，一旦一次移动后满足条件，ans的数量就加一，
    //在第一次满足条件前，只需要不断向右移动就行，
    //在第一次满足条件后，如果再向右移动一次后，仍然满足条件，那么就再将ans加一
    //在第一次满足条件后，如果下一次右移动后不满足条件，就要左侧.向右移动一次
    //然后再判断是否满足条件，若满足则ans加一

}