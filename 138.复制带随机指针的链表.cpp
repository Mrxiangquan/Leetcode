/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,int> hashtable1;
        unordered_map<int,Node*> hashtable2;
        hashtable1[nullptr]=-1;
        hashtable2[-1]=nullptr;
        Node *dummy=new Node(0);
        Node *p1=head,*p2=dummy;
        int num=0;
        //创建一个新的带随机指针的链表，此时random指针还没复制
        while(p1!=nullptr){
            hashtable1[p1]=num;
            p2->next=new Node(p1->val);
            p2=p2->next;
            hashtable2[num]=p2;
            p1=p1->next;
            ++num;
        }
        p1=head,p2=dummy->next;
        while(p1!=nullptr){
            num=hashtable1[p1->random];
            p2->random=hashtable2[num];
            p1=p1->next;
            p2=p2->next;
        }
        return dummy->next;
    }
};*/
/*
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> hashtable;
        hashtable[nullptr]=nullptr;
        Node *dummy=new Node(0);
        Node *p1=head,*p2=dummy;
        //创建一个新的带随机指针的链表，此时random指针还没复制
        while(p1!=nullptr){
            p2->next=new Node(p1->val);
            p2=p2->next;
            hashtable[p1]=p2;
            p1=p1->next;
        }
        p1=head,p2=dummy->next;
        while(p1!=nullptr){
            p2->random=hashtable[p1->random];
            p1=p1->next;
            p2=p2->next;
        }
        return dummy->next;
    }
};*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> hashtable;
        hashtable[nullptr]=nullptr;
        Node *dummy1=new Node(0);
        dummy1->next=head;
        Node *dummy2=new Node(0);
        Node *p1=dummy1,*p2=dummy2;
        //创建一个新的带随机指针的链表，此时random指针还没复制
        while(p1->next!=nullptr){
            if(hashtable.find(p1->next)!=hashtable.end()) p2->next=hashtable[p1->next];
            else{
                p2->next=new Node(p1->next->val);
                hashtable[p1->next]=p2->next;
            }
            if(hashtable.find(p1->next->random)!=hashtable.end()) p2->next->random=hashtable[p1->next->random];
            else{
                p2->next->random=new Node(p1->next->random->val);
                hashtable[p1->next->random]=p2->next->random;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return dummy2->next;
    }
};
// @lc code=end

