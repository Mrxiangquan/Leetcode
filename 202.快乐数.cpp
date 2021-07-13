/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int getSum(int n){
        int temp,sum=0;
        while(n!=0){
            temp=n%10;
            sum+=temp*temp;
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow=n,fast=n;
        while(fast!=1){
            slow=getSum(slow);
            fast=getSum(fast);
            fast=getSum(fast);
            if(slow==fast&&fast!=1) return false;
        }
        return true;
    }
};
// @lc code=end

