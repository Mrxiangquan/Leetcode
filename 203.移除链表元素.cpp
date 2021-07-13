/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode *dummy=new ListNode(0,head);
        ListNode *slow=dummy,*fast=head;
        while(fast){
            if(fast->val!=val){
                slow->next=fast;
                slow=slow->next;
            }
            fast=fast->next;
        }
        slow->next=nullptr;
        return dummy->next;
    }
};
// @lc code=end

