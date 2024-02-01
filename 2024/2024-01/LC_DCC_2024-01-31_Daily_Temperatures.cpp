// LC DCC 2024/01/31
// 739. Daily Temperatures
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> temperatures(n, 0);
        for(int &i: temperatures)
            cin >> i;
        vector<int> ans = ob.dailyTemperatures(temperatures);
        for(int &i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
3
8
73 74 75 71 69 72 76 73
4
30 40 50 60
3
30 60 90

Sample Output
1 1 4 2 1 1 0 0 
1 1 1 0 
1 1 0 

*/