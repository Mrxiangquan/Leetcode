/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickArray(nums,0,nums.size()-1);
        return nums;
    }

    void quickArray(vector<int>& nums,int left,int right){
        if(left<right){
            int i = rand() % (right - left + 1) + left; // 随机选一个作为我们的主元
            swap(nums[i], nums[left]);
            int pos=partiton(nums,left,right);
            quickArray(nums,left,pos-1);
            quickArray(nums,pos+1,right);
        }
    }

    int partiton(vector<int>& nums,int left,int right){
        int pos=left;
        int pivot=nums[left],temp;
        for(int i=left+1;i<=right;++i){
            if(nums[i]<pivot){
                ++pos;
                if(pos!=i){
                    temp=nums[i];
                    nums[i]=nums[pos];
                    nums[pos]=temp;
                }
            }
        }
        nums[left]=nums[pos];
        nums[pos]=pivot;
        return pos;
    }
};
// @lc code=end

