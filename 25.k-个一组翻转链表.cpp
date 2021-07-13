/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    int getListLength(ListNode* head){
        ListNode *temp=head;
        int length=0;
        while(temp){
            ++length;
            temp=temp->next;
        }
        return length;
    }

    vector<ListNode *> reverseList(ListNode *head,int k){
        ListNode *pre=head,*cur=head->next,*temp;
        pre->next=nullptr;
        for(int i=0;i<k-1;++i){
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return {pre,cur};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int length=getListLength(head);
        int num=length/k;
        if(length==0||num==0||k==1) return head;
        vector<ListNode *> temp={head,head};
        ListNode *ans,*newHead=head;

        for(int i=0;i<num;++i){
            temp=reverseList(newHead,k);
            if(i==0) ans=temp[0];
            else{
                head->next=temp[0];
                head=newHead;
            }
            newHead=temp[1];
        }
        head->next=temp[1];
        return ans;
    }
};
// @lc code=end

