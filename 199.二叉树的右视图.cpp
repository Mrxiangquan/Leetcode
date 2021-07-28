/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        vector<int> v;
        TreeNode *temp;
        q.push(root);
        while(!q.empty()){
            int num=q.size();
            for(int i=0;i<num;++i){
                temp=q.front();
                if(i==num-1) v.push_back(temp->val);
                q.pop();
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
        }
        return v;
    }
};
// @lc code=end

