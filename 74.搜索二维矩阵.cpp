/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int raw=matrix.size(),col=matrix[0].size();
        //第一次二分查找找行
        int left=0,right=raw-1,mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]>target) right=mid-1;
            else left=mid+1;
        }
        int pos=right;
        if(pos==-1) return false;
        //第二次二分查找找到列
        left=0,right=col-1;
        while(left<=right){
            mid=left+(right-left)/2;
            if(matrix[pos][mid]==target) return true;
            else if(matrix[pos][mid]>target) right=mid-1;
            else left=mid+1;
        }
        return false;
    }
};
// @lc code=end

