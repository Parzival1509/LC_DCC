// LC DCC 2023/10/15
// 1269. Number of Ways to Stay in the Same Place After Some Steps
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int steps, int ind, int len, vector<vector<int>>& dp) {
        if(steps == 0) return ind == 0;
        
        if(dp[steps][ind] != -1) return dp[steps][ind];

        long long ways = solve(steps - 1, ind, len, dp) % mod;
        if(ind > 0)
            ways += solve(steps - 1, ind - 1, len, dp) % mod;
        if(ind < len - 1)
            ways += solve(steps - 1, ind + 1, len, dp) % mod;

        return dp[steps][ind] = (int)(ways % mod);
    }

    int numWays(int steps, int arrLen) {
        // // Approach 1: Memoization (Top-Down DP)
        // vector<vector<int>> dp(steps + 1, vector<int> (min(arrLen, steps) + 1, -1));
        // return solve(steps, 0, arrLen, dp);

        // // Approach 2: Tabulation (Bottom-Up DP)
        // int n = min(steps / 2 + 1, arrLen);
        
        // vector<vector<int>> dp(steps + 1, vector<int> (n, 0));
        // dp[0][0] = 1;
        
        // for(int i = 1; i <= steps; i++)
        //     for(int j = 0; j < n; j++) {
        //         dp[i][j] = dp[i - 1][j];
        //         if(j > 0)
        //             dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
        //         if(j < n - 1)
        //             dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
        //     }
        
        // return dp[steps][0];

        // Approach 3: Space-Optimized DP
        int max_index = min(steps / 2, arrLen - 1);
        vector<vector<int>> dp(2, vector<int> (max_index + 1, 0));
        dp[0][0] = 1;

        for(int step = 1; step <= steps; ++step) {
            int current = step % 2;
            int prev = (step - 1) % 2;

            for(int index = 0; index <= max_index; ++index) {
                dp[current][index] = dp[prev][index] % mod;
                if(index > 0)
                    dp[current][index] = (dp[current][index] + dp[prev][index - 1]) % mod;
                if(index < max_index)
                    dp[current][index] = (dp[current][index] + dp[prev][index + 1]) % mod;
            }
        }

        return dp[steps % 2][0];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int steps, arrLen;
        cin >> steps >> arrLen;
        cout << ob.numWays(steps, arrLen) << endl;
    }

    return 0;
}

/* Sample Input:
4
3 3
3 2
2 4
4 2

Sample Output:
4
4
2
8

*/