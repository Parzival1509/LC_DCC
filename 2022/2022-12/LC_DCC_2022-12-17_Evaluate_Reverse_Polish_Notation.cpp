// LC DCC 2022/12/17
// 150. Evaluate Reverse Polish Notation
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for(auto st: tokens) {
            if(st=="+") {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(st=="-") {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(st=="*") {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if(st=="/") {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(b/a);
            }
            else s.push(stoi(st));
        }
        return s.top();
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<string> tokens(n);
        for(int i=0; i<n; i++)
            cin>>tokens[i];
        cout<<ob.evalRPN(tokens)<<endl;
    }
}

/* Sample Input
3
5
2 1 + 3 *
5
4 13 5 / +
13
10 6 9 3 + -11 * / * 17 + 5 +

Sample Output
9
6
22

*/