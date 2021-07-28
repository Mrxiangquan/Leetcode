/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string s="";
        paths(root,v,s);
        return v;
    }

    vector<string> paths(TreeNode* root,vector<string>& v,string s){      
        if(root==nullptr) return v;
        if(s!="") s+="->";
        s+=to_string(root->val);
        if(root->left==nullptr&&root->right==nullptr){
            v.push_back(s);
            return v;
        }
        paths(root->left,v,s);
        paths(root->right,v,s);
        return v;
    }
};
// @lc code=end

