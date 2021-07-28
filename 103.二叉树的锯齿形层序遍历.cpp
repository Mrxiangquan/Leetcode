/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        vector<vector<int>> v;
        q.push(root);
        int num;
        TreeNode *temp;
        bool ifLeft=true;
        while(!q.empty()){
            deque<int> d;
            num=q.size();
            for(int i=0;i<num;++i){
                temp=q.front();
                q.pop();
                if(ifLeft) d.push_back(temp->val);
                else d.push_front(temp->val);
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
            v.push_back(vector<int> {d.begin(),d.end()});
            ifLeft=!ifLeft;
        }
        return v;
    }
};
// @lc code=end

