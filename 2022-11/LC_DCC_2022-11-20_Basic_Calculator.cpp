// LC DCC 2022/11/20
// 224. Basic Calculator
// Hard

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();
bool cmp(pair<string, int> A, pair<string, int> B){
    if(A.first != B.first)
        return A.second < B.second;
    return B.first > A.first;
}

// Baijnath's Sol
class Solution {
public:
    int calculate(string s) {
        int ans=0, num=0, sign=1;
        stack<int> stack{{sign}};  // Stack.top(): current env's sign
        for(const char c: s)
            if(isdigit(c))
                num = num*10 + (c-'0');
            else if(c=='(')
                stack.push(sign);
            else if(c==')')
                stack.pop();
            else if(c=='+' || c=='-') {
                ans += sign * num;
                sign = (c=='+'? 1: -1) * stack.top();
                num = 0;
            }
        return ans + sign*num;
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<ob.calculate(s)<<endl;
    }
    return 0;
}

/* Sample Input
3
1 + 1
2-1 + 2
(1+(4+5+2)-3)+(6+8)

Sample Output
45
16

*/