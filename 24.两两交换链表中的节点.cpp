/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *dummy=new ListNode(0,head),*temp=dummy;
        ListNode *first=head,*second=head->next;
        while(first&&second){
            temp->next=second;
            first->next=second->next;
            second->next=first;
            temp=first;
            first=first->next;
            if(first)second=first->next;
            else second=nullptr;

        }
        return dummy->next;
    }
};*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *newhead=head->next;
        head->next=swapPairs(newhead->next);
        newhead->next=head;
        return newhead;
    }
};
// @lc code=end

