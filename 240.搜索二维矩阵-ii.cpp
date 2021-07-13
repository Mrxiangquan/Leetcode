/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int raw=matrix.size(),col=matrix[0].size();
        //第一次二分查找，找到合适的行
        int pos=-1;
        int left=0,right=raw-1,mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]>target) right=mid-1;
            else left=mid+1;
        }
        pos=(right==raw)?raw-1:right;
        //第二次二分查找，找到行内是否有该数
        for(int i=0;i<=pos;++i){
            left=0;right=col-1;
            while(left<=right){
                mid=left+(right-left)/2;
                if(matrix[i][mid]==target) return true;
                else if(matrix[i][mid]>target) right=mid-1;
                else left=mid+1;
            }
        }
        return false;
    }
};*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int raw=matrix.size(),col=matrix[0].size();
        int i=raw-1,j=0;
        while(i>=0&&j<col){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) --i;
            else ++j; 
        }
        return false;
    }
};
// @lc code=end

