#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int win;
    int lose;
    int balance;
    int cwin;
    int jwin;
    int bwin;
}person;

char get_max_gesture(int c, int j, int b) {
    // 如果布胜利次数最多
    if (b >= c && b >= j) {
        return 'B';
    }
    // 如果锤子胜利次数最多
    else if (c >= j && c > b) {
        return 'C';
    }
    // 如果剪刀胜利次数最多
    else {
        return 'J';
    }
}

int main()
{
    int n = 0;//记录双方交锋的次数
    scanf("%d" , &n);
    //printf("%d\n" , n);
    char beatJ = 0;
    char beatY = 0;
    //声明甲乙对象
    person j = {0};
    person y = {0};
    for(int i  = 0 ; i < n ; i++)
    {
        scanf(" %c %c" , &beatJ , &beatY);
        //判定甲乙胜负
        //甲胜 
        if((beatJ == 'C' && beatY == 'J') 
           ||(beatJ == 'J' && beatY == 'B')
           ||(beatJ == 'B' && beatY == 'C'))
        {
            j.win++;
            y.lose++;
            if(beatJ == 'C')
            {
                j.cwin++;
            }
            if(beatJ == 'J')
            {
                j.jwin++;
            }
            if(beatJ == 'B')
            {
                j.bwin++;
            }
        }
        else if(beatJ == beatY)
        {//甲平
            j.balance++;
            y.balance++;
        }
        else 
        {//甲输
            j.lose++;
            y.win++;
            if(beatY == 'C')
            {
                y.cwin++;
            }
            if(beatY == 'J')
            {
                y.jwin++;
            }
            if(beatY == 'B')
            {
                y.bwin++;
            }
        }
    }
    //输出
    printf("%d %d %d\n",j.win , j.balance , j.lose);
    printf("%d %d %d\n" , y.win , y.balance , y.lose);
    // 输出甲的最多胜利手势
    char j_max_gesture = get_max_gesture(j.cwin, j.jwin, j.bwin);
    // 输出乙的最多胜利手势
    char y_max_gesture = get_max_gesture(y.cwin, y.jwin, y.bwin);

    // 输出最终结果
    printf("%c %c", j_max_gesture, y_max_gesture);

    return 0;
}



