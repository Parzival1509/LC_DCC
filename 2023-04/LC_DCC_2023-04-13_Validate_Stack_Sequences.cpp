// LC DCC 2023/04/13
// 946. Validate Stack Sequences
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for(int i: pushed) {
            st.push(i);
            while(!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        while(!st.empty() && st.top() == popped[j]) {
            st.pop();
            j++;
        }
        return (st.empty());
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<int> pushed(n, 0);
        for(int &i: pushed)
            cin>>i;
        vector<int> popped(n, 0);
        for(int &i: popped)
            cin>>i;
        cout<<ob.validateStackSequences(pushed, popped)<<endl;
    }
    return 0;
}

/* Sample Input:
2
5
1 2 3 4 5
4 5 3 2 1
5
1 2 3 4 5
4 3 5 1 2

Sample Output:
1
0

*/