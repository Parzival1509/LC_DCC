// LC DCC 2023/04/10
// 20. Valid Parentheses
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') stk.push(c);
            else {
                if (stk.empty()) return false;
                
                if (c == ')' && stk.top() == '(') stk.pop();
                else if (c == '}' && stk.top() == '{') stk.pop();
                else if (c == ']' && stk.top() == '[') stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        string s;
        cin>>s;
        cout<<ob.isValid(s)<<endl;
    }
    return 0;
}

/* Sample Input:
3
()
(){}[]
(]

Sample Output:
1
1
0

*/