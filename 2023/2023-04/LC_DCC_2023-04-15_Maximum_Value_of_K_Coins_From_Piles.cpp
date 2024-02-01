// LC DCC 2023/04/15
// 2218. Maximum Value of K Coins From Piles
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int solve(int i, vector<vector<int>> &piles, int k, vector<vector<int>> &dp) {
        if(i >= piles.size() || k <= 0) return 0;     
        if(dp[i][k] != -1) return dp[i][k];
        int fur = solve(i+1, piles, k, dp);
        int cur = 0;
        for(int idx=0; idx<piles[i].size() && idx<k; idx++) {
            cur += piles[i][idx]; 
            fur = max(fur, cur + solve(i+1, piles, k-idx-1, dp));
        }
        return dp[i][k] = fur;
    }

    int maxValueOfCoins(vector<vector<int>> &piles, int k) {
        vector<vector<int>> dp(piles.size(), vector<int>(k+1, -1));
        return solve(0, piles, k, dp);
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<vector<int>> piles;
        for(int i=0; i<n; i++) {
            vector<int> tmp;
            piles.push_back(tmp);
        }
        cout<<ob.maxValueOfCoins(piles, k)<<endl;
    }
    return 0;
}

/* Sample Input:
2

2 2
1 100 3
7 8 9

7 7
100
100
100
100
100
100
1 1 1 1 1 1 700

Sample Output:
101
706

*/