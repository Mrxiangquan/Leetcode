/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length=nums.size();
        vector<vector<int> > ans;
        if(length<4) return ans;
        sort(nums.begin(),nums.end());
        int left,right,temp;

        for(int i=0;i<length-3;++i){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<length-2;++j){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                left=j+1;
                right=length-1;
                temp=target-nums[i]-nums[j];
                while(left<right){
                    if(nums[left]+nums[right]==temp){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right&&nums[left]==nums[left+1]) ++left;
                        while(left<right&&nums[right]==nums[right-1]) --right;
                        ++left;
                        --right;
                    }
                    else if(nums[left]+nums[right]<temp) ++left;
                    else --right;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

