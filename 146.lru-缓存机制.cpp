/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
struct MyNode{
    int key;
    int val;
    MyNode *next;
    MyNode(int k=0,int v=0,MyNode *n=nullptr):key(k),val(v),next(n){}
};

class LRUCache {
private:
    int maxCapacity;
    int curCapacity;
    MyNode *dummy;
    MyNode *tail;
    unordered_map<int,MyNode*> hashtable;
    
public:
    LRUCache(int capacity) {
        maxCapacity=capacity;
        curCapacity=0;
        dummy=new MyNode();
        tail=dummy;
    }
    
    int get(int key) {
        if(hashtable.find(key)==hashtable.end()) return -1;
        MyNode *pre=hashtable[key];
        MyNode *cur=pre->next;
        int ans=cur->val;
        if(cur==tail) return ans;
        pre->next=cur->next;
        hashtable[cur->next->key] = pre;
        tail->next=cur;
        hashtable[key]=tail;
        tail=tail->next;
        return ans;
    }
    
    void put(int key, int value) {
        if(hashtable.find(key)!=hashtable.end()){
            hashtable[key]->next->val=value;
            get(key);
            return;
        } 
        if(curCapacity==maxCapacity){
            MyNode *temp=dummy->next;
            dummy->next=temp->next;
            hashtable.erase(temp->key);
            if(maxCapacity!=1) hashtable[temp->next->key] = dummy;
            else tail=dummy;
            delete temp;
            --curCapacity;
        }
        tail->next=new MyNode(key,value);
        //哈希表的key对应的是当前结点的上一个结点，方便访问修改该结点
        hashtable[key]=tail;
        tail=tail->next;
        ++curCapacity;
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

