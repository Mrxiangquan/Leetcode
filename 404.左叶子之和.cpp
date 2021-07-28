/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        int num,sum=0;
        TreeNode *temp;
        while(!q.empty()){
            num=q.size();
            for(int i=0;i<num;++i){
                temp=q.front();
                q.pop();
                if(temp->left!=nullptr){
                    q.push(temp->left);
                    if(temp->left->left==nullptr&&temp->left->right==nullptr) sum+=temp->left->val;
                }
                if(temp->right!=nullptr) q.push(temp->right);
            }
        }
        return sum;
    }
};
// @lc code=end

