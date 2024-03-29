/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        return getDepth(root)==-1?false:true;
    }

    int getDepth(TreeNode* root){
        if(root==nullptr) return 0;
        int leftHeight=getDepth(root->left);
        int rightHeight=getDepth(root->right);
        if(leftHeight==-1||rightHeight==-1||abs(leftHeight-rightHeight)>1) return -1;
        return max(leftHeight,rightHeight)+1;
    }
};
// @lc code=end

