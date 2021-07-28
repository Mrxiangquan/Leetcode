/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
void reorderList(ListNode* head) {
    if(head==nullptr||head->next==nullptr) return ;
    int length=0;
    ListNode *p=head;
    for(;p!=nullptr;p=p->next) ++length;
    length>>=1;
    
    p=head;
    for(int i=0;i<length-1;++i) p=p->next;
    ListNode *lastHead=p->next;
    p->next=nullptr;
    //翻转链表
    ListNode *pre=lastHead,*cur=lastHead->next,*temp;
    pre->next=nullptr;
    while(cur!=nullptr){
        temp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=temp;
    }
    //合并两个链表
    p=head;
    ListNode *temp1;
    for(int i=0;i<length;++i){
        temp=p->next;
        temp1=pre->next;
        p->next=pre;
        pre->next=temp;
        p=temp;
        if(i!=length-1)pre=temp1;
    }
    return ;
}*/


void reorderList(ListNode* head) {
    if(head==nullptr||head->next==nullptr) return ;

    //寻找链表中间点
    ListNode *slow=head,*fast=head;
    while(fast->next!=nullptr&&fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode *l1=head,*l2=slow->next,*l1_temp,*l2_temp;
    slow->next=nullptr;

    //翻转链表
    ListNode *pre=l2,*cur=l2->next,*temp;
    pre->next=nullptr;
    while(cur!=nullptr){
        temp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=temp;
    }

    //合并两个链表
    l2=pre;
    while(l1!=nullptr&&l2!=nullptr){
        l1_temp=l1->next;
        l2_temp=l2->next;

        l1->next=l2;
        l1=l1_temp;
        l2->next=l1;
        l2=l2_temp;
    }
    return ;
}
// @lc code=end

