#include <stdio.h>


//C语言实现归并排序
//2024.9.25

viod mergeSort_upTodown(int* num , int start , int end)
{
	int mid = start + (end - start)/2;
	
	if(start >= end)
	{
		return;
	}
	
	mergeSort_upTodown(num , mid + 1 , end);
	mergeSort_upTodown(num , start , end);
	
	Merge(num, start, mid, end);
}


void Merge(int *num, int start, int mid, int end)
{
	int *temp = (int *)malloc((end-start+1) * sizeof(int));
	int i = start;
	int j = mid + 1;
	int k = 0;
	
	while( i <= mid && j <= end)
	{
           if (num[i] <= num[j])
           {
               temp[k++] = num[i++];
           }
           else
          {
            temp[k++] = num[j++];
          }
	}
	while(i <= mid)
	{
		temp[k++] = num[i++];
	}
	while(j <= end)
	{
		temp[k++] = num[j++];
	}
	
	for(i = 0 ; i < k ; i++)
	{
		num[start + i] = temp[i];
	}
	free(temp);
	
}
