// LC DCC 2023/08/12
// 63. Unique Paths II
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // Approach 1: Memoization
    int helper(vector<vector<int>> &obstacleGrid, int i, int j, vector<vector<int>> &dp) {
        if(i < 0 || j < 0 || obstacleGrid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int left = helper(obstacleGrid, i, j - 1, dp);
        int up = helper(obstacleGrid, i - 1, j, dp);

        return dp[i][j] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m - 1][n - 1] == 1) return 0;

        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return helper(obstacleGrid, m - 1, n - 1, dp);
        
        // Approach 2: Tabulation
        vector<vector<long>> dp(m + 1, vector<long> (n + 1, 0));
        dp[m - 1][n - 1] = 1;
        for(int i = m - 1; i >= 0; i--)
            for(int j = n - 1; j >= 0; j--) {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else dp[i][j] += dp[i][j + 1] + dp[i + 1][j];
            }

        return dp[0][0];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> obstacleGrid(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> obstacleGrid[i][j];
        cout << ob.uniquePathsWithObstacles(obstacleGrid) << endl;
    }

    return 0;
}

/* Sample Input:
2

3 3
0 0 0
0 1 0
0 0 0

2 2
0 1
0 0

Sample Output:
2
1

*/