/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return isMirror(root,root);
    }

    bool isMirror(TreeNode* left,TreeNode* right){
        if(left==nullptr&&right==nullptr) return true;
        if((left==nullptr&&right!=nullptr)||(left!=nullptr&&right==nullptr)) return false;
        return (left->val==right->val)&&isMirror(left->left,right->right)&&isMirror(left->right,right->left);
    }
};*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        TreeNode *left,*right;
        while(!q.empty()){
            left=q.front();q.pop();
            right=q.front();q.pop();
            if(!left&&!right) continue;
            if((left==nullptr&&right!=nullptr)||(left!=nullptr&&right==nullptr)||(left->val!=right->val)) return false;
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};
// @lc code=end

