// LC DCC 2023/04/07
// 1020. Number of Enclaves
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return;
        
        grid[i][j] = 0;
        dfs(i+1, j, grid, m, n);
        dfs(i-1, j, grid, m, n);
        dfs(i, j+1, grid, m, n);
        dfs(i, j-1, grid, m, n);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if ((i == 0 || j == 0 || m-1 == i || n-1 == j) && grid[i][j] == 1)
                    dfs(i, j, grid, m, n);
        
        int s = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                s += grid[i][j];

        return s;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int m, n;
        cin>>m>>n;
        vector<vector<int>> grid(m, vector<int> (n, 0));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>grid[i][j];
        cout<<ob.numEnclaves(grid)<<endl;
    }
    return 0;
}

/* Sample Input:
2

4 4
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0

4 4
0 1 1 0
0 0 1 0
0 0 1 0
0 0 0 0

Sample Output:
3
0

*/