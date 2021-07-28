/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathSum(root,targetSum,0);
    }

    bool pathSum(TreeNode* root,int targetSum,int totalSum){
        if(root==nullptr) return false;
        totalSum+=root->val;
        if(root->left==nullptr&&root->right==nullptr) return targetSum==totalSum;
        return pathSum(root->left,targetSum,totalSum)||pathSum(root->right,targetSum,totalSum);
    }
};
// @lc code=end

