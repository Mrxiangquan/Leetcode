/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
/*
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num=0;
        do{
            if(n&1) ++num;
        }while(n>>=1);
        return num;
    }
};*/
/*
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                ret++;
            }
        }
        return ret;
    }
};*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            n &= n - 1;
            ret++;
        }
        return ret;
    }
};
// @lc code=end

