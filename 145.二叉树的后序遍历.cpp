/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return v;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        v.push_back(root->val);
        return v;
    }
};*/

/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode* > s;
        TreeNode *node=root;
        TreeNode *pre=nullptr;
        while(node!=nullptr||!s.empty()){
            while(node!=nullptr){
                s.push(node);
                node=node->left;
            }
            node=s.top();
            if(node->right==nullptr||node->right==pre){
                pre=node;
                v.push_back(node->val);
                s.pop();
                node=nullptr;
            }else{
                node=node->right;
            }
        }
        return v;
    }
};*/

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
    void printPath(vector<int> &v,TreeNode*& node){
        int count=0;
        while(node!=nullptr){
            ++count;
            v.push_back(node->val);
            node=node->right;
        }
        reverse(v.end()-count,v.end());
    }

    vector<int> postorderTraversal(TreeNode* root) {
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
                    p2->right=nullptr;
                    printPath(v,p1->left);
                    p1=p1->right;
                }
            }else{
                p1=p1->right;
            }
        }
        //输出根节点到最右边叶节点
        printPath(v,root);
        return v;
    }
};
// @lc code=end

