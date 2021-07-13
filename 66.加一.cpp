/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
/*
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(n==0) return digits;
        int sum=0,carry=1;
        for(int i=n-1;i>=0;--i){
            sum=digits[i]+carry;
            digits[i]=sum%10;
            carry=(sum>=10)?1:0;
        }
        if(carry==1) digits.insert(digits.begin(),1);
        return digits;
    }
};
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(n==0) return digits;
        int sum=0,carry=1;
        for(int i=n-1;i>=0;--i){
            sum=digits[i]+carry;
            digits[i]=sum%10;
            if(sum>=10) carry=1;
            else return digits;
        }
        if(carry==1) digits.insert(digits.begin(),1);
        return digits;
    }
};
// @lc code=end

