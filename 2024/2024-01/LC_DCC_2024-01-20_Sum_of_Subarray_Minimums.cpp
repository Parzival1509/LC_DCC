// LC DCC 2024/01/20
// 907. Sum of Subarray Minimums
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7, n = arr.size();
        vector<long> dp(n + 1, 0);
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            int idx = st.size()? st.top(): n;
            dp[i] = ((idx - i) * arr[i] + dp[idx]) % mod;
            st.push(i);
        }
        
        long ans = 0;
        for(int i = 0; i < n; i++)
            ans = (ans + dp[i]) % mod;
        return (int)ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        cout << ob.sumSubarrayMins(arr) << endl;
    }

    return 0;
}

/* Sample Input
2
4
3 1 2 4
5
11 81 94 43 3

Sample Output
17
444

*/