// LC DCC 2023/04/06
// 1254. Number of Closed Islands
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
   void dfs(vector<vector<int>> &grid, int n, int m, int r, int c, int &fl) {
        if (r<0 || c>=m || r>=n || c<0 || grid[r][c]==1) return;

        if (r==0||c==0||r==n-1||c==m-1) fl = 1;
        
        grid[r][c] = 1;
        dfs(grid, n, m , r+1, c, fl);
        dfs(grid, n, m , r-1, c, fl);
        dfs(grid, n, m , r, c+1, fl);
        dfs(grid, n, m , r, c-1, fl);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if (grid[i][j] == 0) {
                    int fl = 0;
                    dfs(grid, n, m, i, j, fl);
                    if(!fl) count++;
                }
        
        return count;
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
        cout<<ob.closedIsland(grid)<<endl;
    }
    return 0;
}

/* Sample Input:
3

5 8
1 1 1 1 1 1 1 0
1 0 0 0 0 1 1 0
1 0 1 0 1 1 1 0
1 0 0 0 0 1 0 1
1 1 1 1 1 1 1 0

3 5
0 0 1 0 0
0 1 0 1 0
0 1 1 1 0

7 7
1 1 1 1 1 1 1
1 0 0 0 0 0 1
1 0 1 1 1 0 1
1 0 1 0 1 0 1
1 0 1 1 1 0 1
1 0 0 0 0 0 1
1 1 1 1 1 1 1

Sample Output:
2
1
2

*/