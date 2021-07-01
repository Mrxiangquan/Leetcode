class CQueue {
public:
    stack<int> s1,s2;
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty()){
            while(!s1.empty()){
                int temp=s1.top();
                s1.pop();
                s2.push(temp);
            }
        }
        if(!s2.empty()) {
            int deleteNum=s2.top();
            s2.pop();
            return deleteNum;
        }
        else return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */