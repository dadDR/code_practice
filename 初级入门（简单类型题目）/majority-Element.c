//返回数组中多数元素
//题目：169.多数元素 ，日期： 2024.9.19 出现问题：使用的冒泡排序时间开销太大
//改进：尝试使用二分排序或者快速排序（在20号改）


int majorityElement(int* nums, int numsSize) {
    //将元素进行单调排序，返回下标为n/2的元素
    for(int i  = 0 ; i < numsSize - 1 ; i++)
    {
        for(int j = 0 ; j < numsSize - i - 1 ; j++)
        {
            if(nums[j] > nums[j + 1])
            {
                int temp = 0;
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    return nums[numsSize/2];
}