int searchInsert(int* nums, int numsSize, int target) {
    //使用二分查找方法，不断逼近查找数组中从左到右第一个大于等于target的值的下标
    int left = 0;
    int right = numsSize - 1;
    int ans = numsSize;
    while(left <= right)
    {
        int mid = ((right - left)/2) + left;
        if(target <= nums[mid])
        {
            ans = mid;
            right = mid - 1 ;
        }
        else
        {
            left = mid + 1;

        }

    }
    return ans;
}