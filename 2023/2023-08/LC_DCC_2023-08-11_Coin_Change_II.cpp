// LC DCC 2023/08/11
// 518. Coin Change II
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // // Approach 1: Memoization
    // int helper(vector<int> coins, int n, int amount, vector<vector<int>> &dp) {
    //     // Base Case
    //     if(amount == 0) return 1;
    //     if(n == 0) return 0;
        
    //     if(dp[n][amount] != -1) return dp[n][amount];

    //     if(coins[n - 1] > amount)
    //         return dp[n][amount] = helper(coins, n - 1, amount, dp);
    //     return dp[n][amount] = helper(coins, n, amount - coins[n - 1], dp) + helper(coins, n - 1, amount, dp);
    // }
    
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));
        
        // return helper(coins, n, amount, dp);

        // Approach 2: Tabulation
        for(int i = 0; i < n + 1 ;i++)
            for(int j = 0; j < amount + 1; j++)
                if(j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = 0;
                else if(coins[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];

        return dp[n][amount];
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int amount, N;
        cin >> amount >> N;
        vector<int> coins(N, 0);
        for(int &i: coins)
            cin >> i;
        Solution ob;
        cout << ob.change(amount, coins) << endl;
    }

    return 0;
}

/* Sample Input:
4
4 3
1 2 3
10 4
2 5 3 6
5 3
1 2 5
3 1
2

Sample Output:
4
5
4
0

*/