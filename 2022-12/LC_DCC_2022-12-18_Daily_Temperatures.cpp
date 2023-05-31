// LC DCC 2022/12/18
// 739. Daily Temperatures
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++) {
            while(!st.empty() && temperatures[st.top()]<temperatures[i]) {
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<int> temps(n);
        for(int i=0; i<n; i++)
            cin>>temps[i];
        for(auto el: ob.dailyTemperatures(temps))
            cout<<el<<' ';
        cout<<endl;
    }
}

/* Sample Input
3
3
30 60 90
4
30 40 50 60
8
73 74 75 71 69 72 76 73

Sample Output
1 1 0 
1 1 1 0 
1 1 4 2 1 1 0 0 

*/