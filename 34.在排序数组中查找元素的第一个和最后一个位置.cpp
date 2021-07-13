/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int leftans=-1,rightans=-1;
        int left=0,right=nums.size()-1,mid;
        //寻找左边界
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]>=target) right=mid-1;
            else left=mid+1;            
        }
        leftans=right;
        //寻找右边界
        left=0,right=nums.size()-1;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]<=target) left=mid+1;
            else right=mid-1;
        }
        rightans=left;
        if(rightans-leftans==1) return {-1,-1};
        else return{leftans+1,rightans-1};
    }
};
// @lc code=end

