// LC DCC 2022/11/25
// 907. Sum of Subarray Minimums
// Medium

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

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7, n=arr.size();
        vector<long> dp(n+1,0);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            int idx = st.size() ? st.top() : n;
            dp[i] = ((idx-i)*arr[i] + dp[idx])%mod;
            st.push(i);
        }
        
        long ans=0;
        for(int i=0; i<n; i++)
            ans = (ans + dp[i])%mod;
        return (int)ans;
    }
};

// // My Sol
// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         long long n=arr.size(), ans=0, m=1e9+7;
//         vector<long long> next_smaller(n), prev_smaller(n);
//         stack<int> s1, s2;
//         for(int i=0; i<n; i++) {
//             next_smaller[i]=n-i-1;
//             prev_smaller[i]=i;
//         }

//         // Finding the next smaller elements indices
//         for(int i=0; i<n; i++) {
//             while(!s1.empty() && arr[s1.top()]>arr[i]) {
//                 next_smaller[s1.top()] = i-s1.top()-1;
//                 s1.pop();
//             }
//             s1.push(i);
//         }

//         // Finding the previous smaller elements indices
//         for(int i=n-1; i>=0; i--) {
//             while(!s2.empty() && arr[s2.top()]>=arr[i]) {
//                 prev_smaller[s2.top()] = s2.top()-i-1;
//                 s2.pop();
//             }
//             s2.push(i);
//         }

//         for(int i=0; i<n; i++) {
//             ans += (next_smaller[i]+1)*(prev_smaller[i]+1)*arr[i];
//             ans %= m;
//         }
//         return ans;
//     }
// };

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<ob.sumSubarrayMins(arr)<<endl;
    }
    return 0;
}

/* Sample Input
3
4
3 1 2 4
4
71 55 82 55
5
11 81 94 43 3

Sample Output
17
593
444

*/