/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

//暴力求解
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        for(int i=0;i<nums.size();i++){
            auto it=hashmap.find(target-nums[i]);
            if(it!=hashmap.end()){
                return {it->second,i};
            }
            hashmap[nums[i]]=i;
        }
        return {};
    }
};
// @lc code=end

