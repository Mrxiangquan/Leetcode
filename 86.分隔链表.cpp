/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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

/*
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode *dummy=new ListNode(0,head);
        ListNode *slow=dummy,*fast=dummy,*temp;
        while(fast->next!=nullptr){
            if(fast->next->val<x){
                if(slow->next!=fast->next){
                    temp=fast->next;
                    fast->next=temp->next;
                    temp->next=slow->next;
                    slow->next=temp;
                }else{
                    fast=fast->next;
                }
                slow=slow->next;
            }else{
                fast=fast->next;
            }
        }
        return dummy->next;
    }
};*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};
// @lc code=end

