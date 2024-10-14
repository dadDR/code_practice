/*
	时间：2024.9.22 朱嘉祺 题目：74.搜索二维矩阵
*/
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    //将矩阵拼接成数组后得到顺序数组，再在顺序数组中进行二分查找
    int m = matrixSize;
    int n = matrixColSize[0];
    int left = 0;
    int right = m*n - 1;
    while(left <= right)
    {
        int mid =  left + (right - left)/2;
        int x = matrix[mid / n][mid % n];
        if( x < target)//现在的值小于要找的值
        {
            left = mid + 1;
        }
        else if(x > target)//现在的值大于要找的值
        {
            right = mid - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}