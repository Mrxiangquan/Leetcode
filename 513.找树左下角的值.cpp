/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        int num,ans;
        TreeNode *temp;
        while(!q.empty()){
            num=q.size();
            for(int i=0;i<num;++i){
                temp=q.front();
                q.pop();
                if(i==0) ans=temp->val;
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
        }
        return ans;
    }
};
// @lc code=end

