/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size()==0) return -1;
        int left=0,right=numbers.size()-1,mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(numbers[right]<numbers[mid]) left=mid+1;
            else if(numbers[right]>numbers[mid]) right=mid;
            else right--;
        }   
        return numbers[right];    
    }
};
// @lc code=end

