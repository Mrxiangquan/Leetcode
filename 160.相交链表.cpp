/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) return nullptr;
        unordered_map<ListNode*,bool> hashtable;
        ListNode *A=headA,*B=headB;
        while(A!=nullptr||B!=nullptr){
            if(A!=nullptr){
                if(hashtable[A]) return A;
                hashtable[A]=true;
                A=A->next;
            }
            if(B!=nullptr){
                if(hashtable[B]) return B;
                hashtable[B]=true;
                B=B->next;
            }
        }
        return nullptr;
    }
};*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) return nullptr;
        ListNode *A=headA,*B=headB;
        while(A!=B){
            if(A!=nullptr) A=A->next;
            else A=headB;
            if(B!=nullptr) B=B->next;
            else B=headA;
        }
        return A;        
    }
}
// @lc code=end

