/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        char temp;
        string s="";
        int i=0,j=0;
        for(;i<strs[0].length();++i){
            temp=strs[0][i];
            j=0;
            for(;j<strs.size();++j){
                if(i>=strs[j].length()||temp!=strs[j][i]) break;
            }
            if(j==strs.size()) s+=temp;
            else return s;
        }
        return s;
    }
};*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0||strs[0].length()==0) return "";
        return longestCommonPrefix(strs,0,strs.size()-1);
    }

    string longestCommonPrefix(vector<string>& strs,int begin,int end){
        if(begin==end) return strs[begin];  
        int mid=begin+(end-begin)/2;
        string left=longestCommonPrefix(strs,begin,mid);
        string right=longestCommonPrefix(strs,mid+1,end);
        return commonPrefix(left,right);
    }

    string commonPrefix(string &s1,string &s2){
        if(s1==""||s2=="") return "";
        int n=(s1.length()<=s2.length())?s1.length():s2.length();
        for(int i=0;i<n;++i){
            if(s1[i]!=s2[i]) return s1.substr(0,i);
        }
        return s1.substr(0,n);
    }
};
// @lc code=end

