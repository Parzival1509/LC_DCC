// LC DCC 2023/06/18
// 2328. Number of Increasing Paths in a Grid
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
private:
    int helper(int i, int j, int prev, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        // Out of boundary and if path is not increasing I can't make a possible path
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || prev >= grid[i][j])
            return 0;

        // If I have answer, use that
        if(dp[i][j] != -1) return dp[i][j];
        
        // Explore: go in all 4 direction to check increasing paths
        ll cnt = 1;

        cnt += helper(i+1, j, grid[i][j], grid, dp) % mod;
        cnt += helper(i-1, j, grid[i][j], grid, dp) % mod;
        cnt += helper(i, j+1, grid[i][j], grid, dp) % mod;
        cnt += helper(i, j-1, grid[i][j], grid, dp) % mod;

        return dp[i][j] = cnt;
    }

public:
    int mod = 1e9 + 7;
    int countPaths(vector<vector<int>>& grid) {
        ll cnt = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cnt += helper(i, j, -1, grid, dp);

        return cnt % mod;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];

        cout << ob.countPaths(grid) << endl;
    }
    return 0;
}

/* Sample Input:
3
5 4
1 5 3 6 7
1 3 2 4
5 3
1 5 3 6 7
4 3 1
5 4
1 5 3 6 7
1 6 3 3

Sample Output:
3
8

*/