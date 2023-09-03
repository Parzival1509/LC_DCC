// LC DCC 2023/08/06
// 920. Number of Music Playlists
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long
    int MOD = 1e9 + 7;

    // Approach 1: Memoization with S.C. = O(n * goal)
    int solve(int n, int goal, int k, vector<vector<int>>& dp) {
        if(n == 0 && goal == 0) return 1;
        if(n == 0 || goal == 0) return 0;
        if(dp[n][goal] != -1) return dp[n][goal];

        ll pick = solve(n - 1, goal - 1, k, dp) * n;
        ll notpick = solve(n, goal - 1, k, dp) * max(n - k, 0);
        return dp[n][goal] = (pick + notpick) % MOD;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        // vector<vector<int>> dp(n + 1, vector<int> (goal + 1, -1));
        // return solve(n, goal, k, dp);

        // Approach 2: Memoization with Rolling Array
        vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));
        dp[0][0] = 1;

        for(int i = 1; i <= goal; i++) {
            dp[i % 2][0] = 0;
            for(int j = 1; j <= min(i, n); j++) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] * (n - (j - 1)) % MOD;
                if(j > k)
                    dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][j] * (j - k)) % MOD;
            }
        }

        return dp[goal % 2][n];
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n, goal, k;
        cin >> n >> goal >> k;
        cout << ob.numMusicPlaylists(n, goal, k) << endl;
    }
    
    return 0;
}

/* Sample Input:
4
3 3 1
2 3 0
2 3 1
16 16 4

Sample Output:
6
6
2
789741546

*/