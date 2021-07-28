/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||k==0) return head;
        int length=0;
        ListNode *p=head,*tail;
        while(p!=nullptr){
            ++length;
            if(p->next==nullptr) tail=p;
            p=p->next;
        }
        k%=length;
        if(k==0) return head;
        p=head;
        for(int i=0;i<length-k-1;++i){
            p=p->next;
        }
        ListNode *newHead=p->next;
        p->next=nullptr;
        
        tail->next=head;
        return newHead;
    }
};
// @lc code=end

