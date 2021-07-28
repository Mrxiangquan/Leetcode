/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode *dummy=new ListNode(0,head);
        ListNode *slow=dummy,*fast=head,*temp;
        while(fast->next!=nullptr){
            if(fast->val<=fast->next->val){
                fast=fast->next;
            }else{
                temp=fast->next;
                fast->next=fast->next->next;
                while(slow!=fast){
                    if(slow->next->val<=temp->val){
                        slow=slow->next;                    
                    }else{
                        temp->next=slow->next;
                        slow->next=temp;
                        break;
                    }
                }
                slow=dummy;
            }
        }
        return dummy->next;
    }
};*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode *dummy=new ListNode(0,head);
        ListNode *slow=head,*fast=head->next;
        while(fast!=nullptr){
            if(slow->val<=fast->val) slow=slow->next;
            else{
                ListNode *temp=dummy;
                while(temp->next->val<=fast->val){
                    temp=temp->next;
                }
                slow->next=fast->next;
                fast->next=temp->next;
                temp->next=fast;
            }
            fast=slow->next;
        }
        return dummy->next;
    }
};
// @lc code=end

