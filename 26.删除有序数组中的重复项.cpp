/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int temp=nums[0];
        for(int i=1;i<nums.size();++i){
            if(temp==nums[i]){
                nums.erase(nums.begin()+i);
                --i;
            }else{
                temp=nums[i];
                continue;
            }
        }
        return nums.size();
    }
};*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int slow=1,fast=1;
        while(fast<n){
            if(nums[fast-1]<nums[fast]){
                nums[slow]=nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
// @lc code=end

