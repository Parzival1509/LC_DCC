// LC DCC 2022/12/16
// 232. Implement Queue using Stacks
// Easy

#include <bits/stdc++.h>
using namespace std;

// Baijnath's Sol
class MyQueue {
private:
    stack<int> s;

public:
    MyQueue() {}

    void push(int x) {
        stack<int> s2;
        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int ret = s.top();
        s.pop();
        return ret;
    }

    int peek() {
        return s.top();
    }

    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        string text1, text2;
        cin>>text1>>text2;
        cout<<ob.longestCommonSubsequence(text1, text2)<<endl;
    }
}

/* Sample Input


Sample Output


*/