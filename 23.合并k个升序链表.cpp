/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> allnum;
        for(int i=0;i<lists.size();i++){
            for(ListNode *p=lists[i];p;p=p->next){
                allnum.push_back(p->val);
            }
        }
        sort(allnum.begin(),allnum.end());
        ListNode *head=new ListNode(0),*newp=head;
        for(int i=0;i<allnum.size();i++){
            newp->next=new ListNode(allnum[i]);
            newp=newp->next;
        }
        return head->next;
    }
};*/
/*
class Solution {
public:
    ListNode* mergeTwoList(ListNode *l1,ListNode *l2){
        if((!l1)||(!l2)) return l1?l1:l2;
        ListNode *p1=l1,*p2=l2;
        ListNode *head=new ListNode(0),*tail=head;
        while(p1&&p2){
            if(p1->val<=p2->val){
                tail->next=p1;
                p1=p1->next;
            }else{
                tail->next=p2;
                p2=p2->next;
            }
            tail=tail->next;
        }
        tail->next=(p1?p1:p2);
        ListNode *temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    ListNode* merge(vector<ListNode*>& lists,int left,int right){
        if(left==right) return lists[left];
        if(left>right) return nullptr;
        int mid=(left+right)>>1;
        return mergeTwoList(merge(lists,left,mid),merge(lists,mid+1,right));
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists,0,lists.size()-1);
    }
};
*/
class Solution {
public:
    struct Status{
        int val;
        ListNode *list;
        bool operator < (const Status& s1) const{
            return val>s1.val;
        }
    };

    priority_queue<Status> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(ListNode *node:lists){
            if(node) q.push({node->val,node});
        }
        ListNode *head=new ListNode(0),*tail=head;
        while(!q.empty()){            
            Status temp=q.top();
            q.pop(); 
            tail->next=temp.list;
            tail=tail->next;
            if(temp.list->next) q.push({temp.list->next->val,temp.list->next});
        }
        return head->next;
    }
};
// @lc code=end

