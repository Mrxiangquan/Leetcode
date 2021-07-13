#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(){
    ListNode *head=new ListNode(-1), *tail=head;
    int val;
    cout << "input the num of list" << endl;
    while(cin>>val){
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    cout << "create success" << endl;
    ListNode *temp = head;
    head = head->next;
    delete temp;
    return head;
}

void outputList(ListNode *head){
    if(!head) {
        cout << "list is numpty" << endl;
        return;
    }
    ListNode *p = head;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    return;
}