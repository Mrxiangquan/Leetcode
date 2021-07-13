/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if(n==0) return 0;
        int slow=0,fast=0;
        while(fast<n){
            if(nums[fast]!=val){
                nums[slow]=nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    } 
};*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }
        return left;
    }
};
// @lc code=end

