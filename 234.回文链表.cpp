/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
private:
    stack<int> s;
    queue<int> q;
public:
    bool isPalindrome(ListNode* head) {
        for(ListNode *tail=head;tail;tail=tail->next){
            s.push(tail->val);
            q.push(tail->val);
        }
        int numOfS=0,numOfQ=0,length=s.size();
        for(int i=0;i<length;i++){
            numOfS=s.top();
            numOfQ=q.front();
            s.pop();
            q.pop();
            if(numOfS!=numOfQ) return false;
        }
        return true;
    }
};*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return false;
        //找到反转链表的位置,slow为反转的位置
        ListNode *fast=head,*slow=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *cur=slow->next,*pre=slow,*temp;
        slow->next=nullptr;
        while(cur){
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        //后半部分链表的头指针为pre,且后半部分长度大于等于前半部分
        temp=head;
        while(pre){
            if(temp->val!=pre->val) return false;
            temp=temp->next;
            pre=pre->next;
        }
        return true;
    }
};
// @lc code=end

