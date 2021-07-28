/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode *dummy=new ListNode(0,head);
        ListNode *cur,*pre=dummy,*temp;
        for(int i=0;i<left-1;++i) pre=pre->next;
        //记录开始反转的链表的上一个节点
        ListNode *begin=pre,*newHead=pre->next;
        pre=pre->next;
        cur=pre->next;
        //开始反转
        for(int i=left;i<right;++i){
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        //反转结束，将现在链表接到原链表中
        newHead->next=cur;
        begin->next=pre;
        return dummy->next;
    }
};
// @lc code=end

