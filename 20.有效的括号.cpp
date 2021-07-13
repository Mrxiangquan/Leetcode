/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        if(n==0||n%2==1) return false;
        stack<char> st;
        for(char c:s){
            if(c=='(') st.push(')');
            else if(c=='[') st.push(']');
            else if(c=='{') st.push('}');
            else if(st.empty()||c!=st.top()) return false;
            else st.pop();
        }
        if(st.empty()) return true;
        else return false;
    }
};
// @lc code=end

