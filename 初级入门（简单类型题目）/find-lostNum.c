//题号：268 丢失的数字 二分查找 ： 2024.9.23

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //将数组排序，之后遇到的下标和数字不符合的元素就是丢失的元素
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] != i)
            {
                return  i;
            }
        }
        return n;
    }
};