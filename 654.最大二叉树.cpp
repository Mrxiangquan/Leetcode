/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    int findMax(vector<int> &nums,int left,int right){
        int pos=left;
        for(int i=left;i<=right;++i){
            if(nums[pos]<nums[i]) pos=i;
        }
        return pos;
    }

    TreeNode* buildTree(vector<int> &nums,int left,int right){
        if(left>right) return nullptr;
        int newLoc=findMax(nums,left,right);
        TreeNode *root=new TreeNode(nums[newLoc]);
        root->left=buildTree(nums,left,newLoc-1);
        root->right=buildTree(nums,newLoc+1,right);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums,0,nums.size()-1);
    }
};
// @lc code=end

