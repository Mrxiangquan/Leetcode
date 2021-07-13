/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1=l1,*p2=l2;
        ListNode *head=new ListNode(0),*p3=head;
        while(p1&&p2){
            if(p1->val<=p2->val){
                p3->next=new ListNode(p1->val);
                p1=p1->next;
            }else{        
                p3->next=new ListNode(p2->val);
                p2=p2->next;
            }       
            p3=p3->next;
        }
        ListNode *temp=(p1)?p1:p2;
        p3->next=temp;
        return head->next;
    }
};
*/

/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1=l1,*p2=l2;
        ListNode *head=new ListNode(0),*p3=head;
        while(p1&&p2){
            if(p1->val<=p2->val){
                p3->next=p1;
                p1=p1->next;
            }else{        
                p3->next=p2;
                p2=p2->next;
            }       
            p3=p3->next;
        }
        ListNode *temp=(p1)?p1:p2;
        p3->next=temp;
        return head->next;
    }
};
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// @lc code=end

