/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int length=nums.size();
        if(length<3) return 0;
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int left,right,temp;

        for(int i=0;i<length-2;++i){
            if(i>0&&nums[i]==nums[i-1]) continue;
            left=i+1;
            right=length-1;

            while(left<right){
                int temp=target-nums[i]-nums[left]-nums[right];
                if(abs(temp)<abs(ans)) ans=temp;
                if(temp==0) return target;
                else if(temp>0) ++left;
                else --right;
            }
        }
        return target-ans;
    }
};
// @lc code=end

