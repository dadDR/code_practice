#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义月饼结构体
typedef struct
{
    int stock;//总量
    int totalPrice;//总价
    float unitPrice;//单价(每万吨)
}moonCake;


//需要计算每种月饼的每吨平均价格
float avergePricecal(int totalPrice, int totalNum)
{
    return (float)totalPrice / (float)totalNum;
}

//按照单价将月饼结构体降序排序
int moonCakecmp(const void*  a, const void*  b)
{
    moonCake *cakeA = (moonCake *)a; // 将 void* 类型转换为 moonCake* 类型
    moonCake *cakeB = (moonCake *)b;
    
    if (cakeA->unitPrice < cakeB->unitPrice)
        return 1;
    else if (cakeA->unitPrice > cakeB->unitPrice)
        return -1;
    else
        return 0;
	
   // return *(moonCake*)a.unitPrice < *(moonCake*)b.unitPrice;
}

int main()
{
    int n = 0;//月饼种类
    int d = 0;//市场最大需求量
    scanf("%d %d" , &n , &d);
    moonCake* moonCakegroup = (moonCake*)malloc(sizeof(moonCake) * n);
    //接收每种月饼的库存量和总售价
    //接收库存量
    for(int i = 0 ; i < n ; i++)
    {
        scanf(" %d" , &(moonCakegroup[i].stock));
       // printf("%d\n"  , moonCakegroup[i].stock);
    }
    //接收总价和计算单价
    for(int i = 0 ; i < n ; i++)
    {
        scanf(" %d" , &(moonCakegroup[i].totalPrice));
        //计算单价
        moonCakegroup[i].unitPrice = avergePricecal(moonCakegroup[i].totalPrice,moonCakegroup[i].stock);
       // printf("%d\n" , moonCakegroup[i].totalPrice);
       // printf("%f\n" , moonCakegroup[i].unitPrice);
    }
    //对月饼进行排序，将最高单价的排在最前面
    qsort(moonCakegroup,n,sizeof(moonCake),moonCakecmp);
    int i = 0;
    float ans = 0;
    while(d != 0)
    {
        if(moonCakegroup[i].stock >= d)
        {
            ans += moonCakegroup[i].unitPrice * d;
            printf("%.2f" , ans);
            return 0;
        }
        else
        {
            ans += moonCakegroup[i].unitPrice * moonCakegroup[i].stock;
            d -= moonCakegroup[i].stock;
        }
        
    }
    return 0;
}