// LC DCC 2023/03/31
// 1444. Number of Ways of Cutting a Pizza
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;
    int dfs(int m, int n, int k, int r, int c, vector<vector<vector<int>>>& dp, vector<vector<int>>& preSum) {
        if (preSum[r][c] == 0) return 0; 
        if (k == 0) return 1; 
        if (dp[k][r][c] != -1) return dp[k][r][c];
        int ans = 0;

        for (int nr = r + 1; nr < m; nr++) 
            if (preSum[r][c] - preSum[nr][c] > 0)
                ans = (ans + dfs(m, n, k - 1, nr, c, dp, preSum)) % mod;

        for (int nc = c + 1; nc < n; nc++) 
            if (preSum[r][c] - preSum[r][nc] > 0)
                ans = (ans + dfs(m, n, k - 1, r, nc, dp, preSum)) % mod;

        return dp[k][r][c] = ans;
    }

    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<vector<int>>> dp(vector(k, vector(m, vector(n, -1))));
        vector<vector<int>> preSum(vector(m+1, vector(n+1, 0)));

        for (int r = m - 1; r >= 0; r--)
            for (int c = n - 1; c >= 0; c--)
                preSum[r][c] = preSum[r][c+1] + preSum[r+1][c] - preSum[r+1][c+1] + (pizza[r][c] == 'A');
        
        return dfs(m, n, k-1, 0, 0, dp, preSum);
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int rows, cols, k;
        cin>>rows>>cols>>k;
        vector<string> pizza(rows);
        for(auto &i: pizza)
            cin>>i;
        cout<<ob.ways(pizza, k)<<endl;
    }
    return 0;
}

/* Sample Input:
3

3 3 3
A..
AAA
...

3 3 3
A..
AA.
...

3 3 1
A..
A..
...

Sample Output:
3
1
1

*/