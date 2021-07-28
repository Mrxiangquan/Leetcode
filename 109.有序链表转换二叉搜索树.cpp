/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) return nullptr;
        int length=0;
        ListNode *p=head;
        while(p){
            ++length;
            p=p->next;
        }
        return buildTree(head,0,length-1);
    }

    TreeNode* buildTree(ListNode* &head,int left,int right){
        if(left>right) return nullptr;
        int mid=left+(right-left)/2;
        TreeNode *root=new TreeNode();
        root->left=buildTree(head,left,mid-1);
        root->val=head->val;
        head=head->next;
        root->right=buildTree(head,mid+1,right);
        return root;
    }
};
// @lc code=end

