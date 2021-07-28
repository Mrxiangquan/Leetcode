/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int> > v{};
        queue<TreeNode*> q;
        unordered_map<TreeNode*,int> hashtable;
        int height=-1;
        hashtable[root]=0;
        q.push(root);
        TreeNode *temp;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            if(hashtable[temp]>height){
                ++height;
                v.push_back(vector<int> ());
            }
            v[height].push_back(temp->val);
            if(temp->left!=nullptr) {
                q.push(temp->left);
                hashtable[temp->left]=height+1;
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
                hashtable[temp->right]=height+1;
            }
        }
        return v;
    }
};*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q;
         vector<vector<int>> v;
        q.push(root);
        int num;
        TreeNode *temp;
        while(!q.empty()){
            num=q.size();
            v.push_back(vector<int> ());
            for(int i=0;i<num;++i){
                temp=q.front();
                q.pop();
                v.back().push_back(temp->val);
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
        }
        return v;
    }
};
// @lc code=end

