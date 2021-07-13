/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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

/*
class Solution {
public:
    //简单思路：第一次遍历得到链表长度，第二次删除
    /*
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listLength=0;
        ListNode* p=head;
        for(;p;p=p->next)  ++listLength;
        if(!head||n>listLength) return head;
        //删除头指针
        if(n==listLength){
            ListNode *temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        p=head;
        for(int i=0;i<listLength-n-1;i++) p=p->next;
        ListNode *temp=p->next;
        p->next=p->next->next;
        delete temp;
        return head;
    }
}
*/

/*
class Solution {
public:
    //扫描一遍的思路：双指针同时循环，后指针距离前指针n个结点，后指针指向
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        ListNode *firstPoint=head,*secondPoint=head,*temp;
        for(int i=0;i<n;i++){
            secondPoint=secondPoint->next;
            if(!secondPoint){
                //n比链表长度大
                if(i<n-1){
                    return head;
                }else{
                    //说明要删除头指针
                    temp=head;
                    head=head->next;
                    delete temp;
                    return head;
                }
            }
        }
        while(secondPoint->next){
            firstPoint=firstPoint->next;
            secondPoint=secondPoint->next;
        }
        temp=firstPoint->next;
        firstPoint->next=firstPoint->next->next;
        delete temp;
        return head;
    }
};*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(0,head);
        ListNode *first=dummy,*second=head;
        for(int i=0;i<n;++i){
            second=second->next;
        }
        while(second){
            first=first->next;
            second=second->next;
        }
        ListNode *temp=first->next;
        first->next=first->next->next;
        delete temp;
        ListNode *answer=dummy->next;
        delete dummy;
        return answer;
    }
};
// @lc code=end

