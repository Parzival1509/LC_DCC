// LC DCC 2023/08/28
// 225. Implement Stack Using Queues
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class MyStack {
public:
    queue<int> a, b;

    MyStack() {}
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        while(a.size() > 1) {
            int x = a.front();
            a.pop();
            b.push(x);
        }

        int x = a.front();
        a.pop();
        while(!b.empty()) {
            int x = b.front();
            b.pop();
            a.push(x);
        }

        return x;
    }
    
    int top() {
        return a.back();
    }
    
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
*/

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        
    }

    return 0;
}

/* Sample Input:
2
8
0 1 3 5 6 8 12 17
8
0 1 2 3 4 8 9 11

Sample Output:
true 
false 

*/