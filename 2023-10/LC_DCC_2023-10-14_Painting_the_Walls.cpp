// LC DCC 2023/10/14
// 2742. Painting the Walls
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int solve(vector<int>& cost, vector<int>& time, vector<vector<int>>& dp, int i, int w) {
        if(w <= 0) return 0;
        if(i >= cost.size()) return 1e9;
        
        if(dp[i][w] != -1) return dp[i][w];

        int notTake = 0 + solve(cost, time, dp, i + 1, w);
        int take = cost[i] + solve(cost, time, dp, i + 1, w - time[i] - 1);

        return dp[i][w] = min(notTake, take);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        // // Approach 1: Memoization
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solve(cost, time, dp, 0, n);

        // Approach 2: Tabulation with Space Optimisation
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for(int i = 0; i < n; i++)
            for(int j = n; j > 0; j--) {
                int k = max(0, j - time[i] - 1);
                dp[j] = min(dp[j], dp[k] + cost[i]);
            }

        return dp[n];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> cost(n, 0);
        for(int &i: cost)
            cin >> i;
        vector<int> time(n, 0);
        for(int &i: time)
            cin >> i;
        cout << ob.paintWalls(cost, time) << endl;
    }

    return 0;
}

/* Sample Input:
2
4
1 2 3 2
1 2 3 2
4
2 3 4 2
1 1 1 1

Sample Output:
3
4

*/