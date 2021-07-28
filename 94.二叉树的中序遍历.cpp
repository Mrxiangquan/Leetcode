/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> v;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return v;
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
        return v;
    }
};*/

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode* > s;
        TreeNode *node=root;
        while(node!=nullptr||!s.empty()){
            while(node!=nullptr){
                s.push(node);
                node=node->left;
            }
            node=s.top();
            v.push_back(node->val);
            s.pop();
            node=node->right;
        }
        return v;
    }
};*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> v;
        TreeNode *p1=root,*p2=nullptr;
        while(p1!=nullptr){
            p2=p1->left;
            if(p2!=nullptr){
                while(p2->right!=nullptr&&p2->right!=p1){
                    p2=p2->right;
                }
                if(p2->right==nullptr){
                    p2->right=p1;
                    p1=p1->left;
                }else{
                    v.push_back(p1->val);
                    p1=p1->right;
                    p2->right=nullptr;
                }
            }else{
                v.push_back(p1->val);
                p1=p1->right;
            }
        }
        return v;
    }
};
// @lc code=end

