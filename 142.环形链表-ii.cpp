/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        unordered_map<ListNode*, bool> hashtable;
        ListNode *p=head;
        int i=0;
        while(p){
            if(hashtable[p]) return p;
            else hashtable[p]=true;
            p=p->next;
        } 
        return nullptr;      
    }
};*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode *slow=head,*fast=head;
        while(fast){
            if(fast->next==nullptr) return nullptr;
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                ListNode *temp=head;
                while(slow!=temp){
                    temp=temp->next;
                    slow=slow->next;     
                }  
                return temp;           
            }
        }
        return nullptr;
    }
};
// @lc code=end

