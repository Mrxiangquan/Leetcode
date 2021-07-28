/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
/*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }

    bool isValidBST(TreeNode* root,long long low,long long high){
        if(root==nullptr) return true;
        if(root->val<=low||root->val>=high) return false;
        return isValidBST(root->left,low,root->val)&&isValidBST(root->right,root->val,high); 
    }
};*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        stack<TreeNode* > s;
        TreeNode *node=root;
        long long pre=LONG_MIN;
        while(node!=nullptr||!s.empty()){
            while(node!=nullptr){
                s.push(node);
                node=node->left;
            }
            node=s.top();
            if(node->val<=pre) return false;
            pre=node->val;
            node=node->right;
            s.pop();
        }
        return true;
    }
};
// @lc code=end

