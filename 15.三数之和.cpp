/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        int length=nums.size();
        if(length<3) return ans;
        sort(nums.begin(),nums.end());
        int target,left,right;

        for(int i=0;i<length-2;++i){
            if(nums[i]>0) break;
            if(i>0&&nums[i-1]==nums[i]) continue;
            left=i+1;
            right=length-1;
            target=-nums[i];

            while(left<right){
                if(nums[left]+nums[right]==target){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    while(left<right&&nums[left]==nums[left+1]) ++left;
                    while(left<right&&nums[right]==nums[right-1]) --right;
                    ++left;
                    --right;
                }else if(nums[left]+nums[right]>target) --right;
                else ++left;
            }
        }
        return ans;
    }
};
// @lc code=end

