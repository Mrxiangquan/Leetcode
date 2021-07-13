#include"leetcodeIO.h"

bool isValid(string s) {
    if(s.length()==0) return true; 
    stack<char> st;
    char temp;
    cout << s.length();
    for(int i=0;i<s.length();++i){
        if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
        else {
            temp=st.top();
            if(s[i]==')'&&temp=='('||s[i]=='['&&temp==']'||s[i]=='{'&&temp=='}') st.pop();
            else return false;
        }
    }
    return true;
}

int main(){
    string s = "()[]{}";
    cout << isValid(s);
    system("pause");
}
