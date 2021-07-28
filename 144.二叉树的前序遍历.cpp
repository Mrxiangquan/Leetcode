/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return v;
        v.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return v;
    }
};*/
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> v;
        stack<TreeNode* > s;
        TreeNode *temp;
        s.push(root);
        while(!s.empty()){
            temp=s.top();
            s.pop();
            v.push_back(temp->val);
            if(temp->right!=nullptr) s.push(temp->right);
            if(temp->left!=nullptr) s.push(temp->left);
        }
        return v;
    }
};*/
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode *node=root;
        while(node!=nullptr||!s.empty()){
            while(node!=nullptr){
                v.push_back(node->val);
                s.push(node);
                node=node->left;
            }
            node=s.top();
            s.pop();
            node=node->right;
        }
        return v;
    }
};*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                    v.push_back(p1->val);
                    p2->right=p1;
                    p1=p1->left;
                }else{
                    p1=p1->right;
                    //这行代码可以在第二次访问到结点时将线索删除掉，在leetcode中，不添加这行代码会报错
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

