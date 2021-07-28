/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int> > v;
        queue<TreeNode* > q;
        q.push(root); 
        while(!q.empty()){
            int num=q.size();
            v.push_back(vector<int> ());
            for(int i=0;i<num;++i){
                TreeNode *node=q.front();
                v.back().push_back(node->val);
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
// @lc code=end

