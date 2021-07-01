/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        int sum = 0, carry = 0;
        while (l1||l2||carry){
            sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            if(carry){
                sum += carry;
            }
            carry = sum >= 10 ? 1 : 0;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};
// @lc code=end

