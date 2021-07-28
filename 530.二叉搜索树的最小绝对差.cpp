/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
private:
    int ans=INT_MAX;
public:
    int getMin(TreeNode *root){
        int leftMin=INT_MAX,rightMin=INT_MAX;
        if(root->left==nullptr&&root->right==nullptr) return -1;
        if(root->left!=nullptr){
            TreeNode *node=root->left;
            while(node->right!=nullptr) node=node->right;
            leftMin=root->val-node->val;
        }
        if(root->right!=nullptr){
            TreeNode *node=root->right;
            while(node->left!=nullptr) node=node->left;
            rightMin=node->val-root->val;
        }
        return min(leftMin,rightMin);
    }

    int getMinimumDifference(TreeNode* root) {
        if(root==nullptr) return ans;
        int min=getMin(root);
        if(min!=-1&&min<ans) ans=min;
        getMinimumDifference(root->left);
        getMinimumDifference(root->right);
        return ans;
    }
};*/
class Solution {
public:
    void dfs(TreeNode *root,int& pre,int &ans){
        if(root==nullptr) return ;
        dfs(root->left,pre,ans);
        if(pre!=-1) ans=min(ans,root->val-pre);
        pre=root->val;
        dfs(root->right,pre,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int pre=-1,ans=INT_MAX;
        dfs(root,pre,ans);
        return ans;
    }
};
// @lc code=end

