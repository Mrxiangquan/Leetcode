/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
/*
class Solution {
private:
    stack<int> s;
    queue<int> q;
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int numofS,numofQ;
        do{
            q.push(x%10);
            s.push(x%10);
        }while(x/=10);
        while(!q.empty()){
            numofQ=q.front();
            numofS=s.top();
            q.pop();
            s.pop();
            if(numofS!=numofQ) return false;
        }
        return true;
    }
};*/

/*
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int> v;
        do{
            v.push_back(x%10);
        }while(x/=10);
        for(int i=0,j=v.size()-1;i<j;i++,j--){
            if(v[i]!=v[j]) return false;
        }
        return true;
    }
};*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||x%10==0&&x!=0) return false;
        int reverseNum=0;
        while(x>reverseNum){
            reverseNum=reverseNum*10+x%10;
            x/=10;
        }
        return x==reverseNum||x==reverseNum/10;
    }
};
// @lc code=end

