/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int num,count=0,maxCount=1;
    vector<int> ans;
public:
    void update(int val){
        if(num==val) ++count;
        else{
            num=val;
            count=1;
        }
        if(count==maxCount) ans.push_back(num);
        else if(count>maxCount){
            maxCount=count;
            ans={num};
        }
    }

    vector<int> findMode(TreeNode* root) {
        if(root==nullptr) return ans;
        findMode(root->left);
        update(root->val);
        findMode(root->right);
        return ans;
    }
};
// @lc code=end

