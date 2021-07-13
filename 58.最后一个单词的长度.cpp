/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length()==0) return 0;
        int length=0;
        for(int i=s.length()-1;i>=0;--i){
            if(length!=0&&s[i]==' ') return length;
            if(s[i]!=' ') ++length;
        }
        return length;
    }
};
// @lc code=end

