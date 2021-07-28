/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int level=0;
        TreeNode *node=root;
        while(node!=nullptr){
            ++level;
            node=node->right;
        }
        int left=1<<level,right=(1<<(level+1))-1,mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(ifexists(root,level,mid)) left=mid+1;
            else right=mid-1;
        }
        return right;
    }

    bool ifexists(TreeNode* root,int level,int counts){
        int bits=1<<(level-1);
        TreeNode *node=root;
        while(node!=nullptr&&bits){
            if((counts&bits)==0) node=node->left;
            else node=node->right;
            bits>>=1; 
        }
        return node!=nullptr;
    }
};
// @lc code=end

