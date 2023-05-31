// LC DCC 2022/11/22
// 279. Perfect Squares
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

// Baijnath's Sol
class Solution {
public:
    int solveMemo(int n,vector<int>& dp){
        if(n == 0)return 0;
        if(dp[n] != INT_MAX)return dp[n];
        int ans = INT_MAX;
        for(int i=1; i*i <= n ;i++){
            ans = min(ans,solveMemo(n-i*i,dp)+1);
        }
        dp[n] = ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        return solveMemo(n,dp);
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ob.numSquares(n)<<endl;
    }
    return 0;
}

/* Sample Input
2
43
13

Sample Output
3
2

*/