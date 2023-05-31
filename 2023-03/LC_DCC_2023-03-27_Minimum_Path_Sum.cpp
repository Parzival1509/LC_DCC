// LC DCC 2023/03/27
// 64. Minimum Path Sum
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row, vector<int> (col, 0));

        dp[0][0] = grid[0][0];

        for(int i=1; i<col; i++)
            dp[0][i] = grid[0][i] + dp[0][i-1];

        for(int i=1; i<row; i++)
            dp[i][0] = grid[i][0] + dp[i-1][0];

        for(int i=1; i<row; i++)
            for(int j=1; j<col; j++)
                dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);

        return dp[row-1][col-1];
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int m, n;
        cin>>m>>n;
        vector<vector<int>> grid(m, vector<int> (n, 0));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>grid[i][j];

        cout<<ob.minPathSum(grid)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3 3
1 3 1
1 5 1
4 2 1
2 3
1 2 3
4 5 6

Sample Output:
7
12

*/