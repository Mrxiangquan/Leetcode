/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hashtable{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int i=0,sum=0,cur=0,next=0;
        for(;i<s.length()-1;++i){
            cur=hashtable[s[i]];
            next=hashtable[s[i+1]];
            if(cur>=next) sum+=cur;
            else{
                sum+=next-cur;
                ++i;
            }
        }
        if(i!=s.length()) sum+=hashtable[s[s.length()-1]];
        return sum;
    }
};
// @lc code=end

