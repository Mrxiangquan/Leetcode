/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int length=height.size();
        if(length<2) return 0;
        int left=0,right=length-1;
        int ans=0;
        while(left<right){
            if(height[left]<height[right]){
                ans=max(ans,height[left]*(right-left));
                ++left;
            }else{
                ans=max(ans,height[right]*(right-left));
                --right;
            }
        }
        return ans;
    }
};
// @lc code=end

