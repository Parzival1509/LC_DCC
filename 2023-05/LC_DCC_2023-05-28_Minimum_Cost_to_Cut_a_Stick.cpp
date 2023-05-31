// LC DCC 2023/05/28
// 1547. Minimum Cost to Cut a Stick
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int helper(int i, int j, vector<int> &cuts,  vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int minm = INT_MAX;
        for(int ind = i; ind <= j; ind++) {
            int cost = cuts[j+1] - cuts[i-1] + helper(i, ind-1, cuts, dp) + helper(ind+1, j, cuts, dp);
            minm = min(minm, cost);
        }
        
        return dp[i][j] = minm;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));

        return helper(1, c, cuts, dp);
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<int> cuts(m, 0);
        for(int &i: cuts)
            cin>>i;

        cout<<ob.minCost(n, cuts)<<endl;
    }
    return 0;
}

/* Sample Input:
2
7 4
1 3 4 5
9 5
5 6 1 4 2

Sample Output:
16
22

*/