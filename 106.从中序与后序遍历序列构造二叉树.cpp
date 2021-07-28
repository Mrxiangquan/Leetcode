/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
private:
    unordered_map<int,int> hashtable;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();++i){
            hashtable[inorder[i]]=i;
        }
        int postLoc=postorder.size()-1;
        return postTree(inorder,postorder,postLoc,0,inorder.size()-1);
    }

    TreeNode* postTree(vector<int>& inorder,vector<int> &postorder,int &postLoc,int left,int right){
        if(left>right) return nullptr;
        TreeNode *root=new TreeNode(postorder[postLoc]);
        int newLoc=hashtable[postorder[postLoc]];
        --postLoc;
        root->right=postTree(inorder,postorder,postLoc,newLoc+1,right);
        root->left=postTree(inorder,postorder,postLoc,left,newLoc-1);
        return root;
    }
};
// @lc code=end

