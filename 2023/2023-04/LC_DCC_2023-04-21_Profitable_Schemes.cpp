// LC DCC 2023/04/21
// 879. Profitable Schemes
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // // Approach 1:
    // int mod = 1e9 + 7;
    // int memo[101][101][101];
    
    // int find(int pos, int count, int profit, int n, int minProfit, vector<int>& group, vector<int>& profits) {
    //     // If profit exceeds the minimum required, it's a profitable scheme.
    //     if(pos == group.size()) return profit >= minProfit;
        
    //     // Repeated subproblem, return the stored answer.
    //     if(memo[pos][count][profit] != -1) return memo[pos][count][profit];
        
    //     // Ways to get a profitable scheme without this crime.
    //     int totalWays = find(pos + 1, count, profit, n, minProfit, group, profits);
    //     // Adding ways to get profitable schemes, including this crime.
    //     if(count + group[pos] <= n)
    //         totalWays += find(pos + 1, count + group[pos], min(minProfit, profit + profits[pos]), n, minProfit, group, profits);
        
    //     return memo[pos][count][profit] = totalWays % mod;
    // }
             
    // int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    //     memset(memo, -1, sizeof(memo));
    //     return find(0, 0, 0, n, minProfit, group, profit);
    // }

    // Approach 2:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int k = 0; k < group.size(); k++) {
            int g = group[k], p = profit[k];
            for (int i = minProfit; i >= 0; i--)
                for (int j = n - g; j >= 0; j--) {
                    int newProfit = min(i + p, minProfit);
                    dp[newProfit][j + g] += dp[i][j];
                    dp[newProfit][j + g] %= MOD;
                }
        }
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += dp[minProfit][i];
            sum %= MOD;
        }
        return sum;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, minProfit, crimes;
        cin>>n>>minProfit>>crimes;
        vector<int> group(crimes, 0), profit(crimes, 0);
        for(auto &i: group)
            cin>>i;
        for(auto &i: profit)
            cin>>i;
        cout<<ob.profitableSchemes(n, minProfit, group, profit)<<endl;
    }
    return 0;
}

/* Sample Input:
2
5 3 2
2 2
2 3
10 5 3
2 3 5
6 7 8

Sample Output:
2
7

*/