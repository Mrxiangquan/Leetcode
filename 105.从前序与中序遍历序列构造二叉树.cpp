/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    unordered_map<int,int> hashtable;
public:
    TreeNode* preTree(vector<int>& preorder,vector<int>& inorder,int &preLoc,int left,int right){
        if(left>right) return nullptr;
        TreeNode *root=new TreeNode(preorder[preLoc]);
        int newLoc=hashtable[preorder[preLoc]];
        ++preLoc;
        root->left=preTree(preorder,inorder,preLoc,left,newLoc-1);
        root->right=preTree(preorder,inorder,preLoc,newLoc+1,right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();++i){
            hashtable[inorder[i]]=i;
        }
        int preLoc=0;
        TreeNode *root=preTree(preorder,inorder,preLoc,0,inorder.size()-1);
        return root;
    }
};*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;
        TreeNode *root=new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        s.push(root);
        int index=0;
        for(int i=1;i<preorder.size();++i){
            int num=preorder[i];
            TreeNode *node=s.top();
            if(inorder[index]!=node->val){
                node->left=new TreeNode(num);
                s.push(node->left);
            } else{
                while(!s.empty()&&s.top()->val==inorder[index]){
                    node=s.top();
                    s.pop();
                    ++index;
                }
                node->right=new TreeNode(num);
                s.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end

