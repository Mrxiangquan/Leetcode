/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        int intTable[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string stringTable[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string s;
        int i=0;
        while(num>0){
            if(num<intTable[i]) ++i;
            else{
                s+=stringTable[i];
                num-=intTable[i];                
            }
        }
        return s;
    }
};
// @lc code=end

