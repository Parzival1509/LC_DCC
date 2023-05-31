// LC DCC 2022/12/31
// 980. Unique Paths III
// Hard

#include <bits/stdc++.h>
using namespace std;

// Baijnath's Sol
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zero=0, sx=0, sy=0;

        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==0) zero++;
                else if(grid[i][j]==1) {
                    sx=i;
                    sy=j;
                }
        return dfs(grid, sx, sy, zero);
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int zero) {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==-1)
            return 0;
        if(grid[x][y]==2)
            return zero == -1?1:0;
        grid[x][y] = -1;
        zero--;
        int totalpaths = dfs(grid, x+1, y, zero) + dfs(grid, x-1, y, zero) + dfs(grid, x, y+1, zero) +
        dfs(grid, x, y-1, zero);
        grid[x][y] = 0;
        zero++;
        return totalpaths;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int m, n;
        cin>>m>>n;
        vector<vector<int>> grid(m, vector<int> (n, 0));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>grid[i][j];
        cout<<ob.uniquePathsIII(grid)<<endl;
    }
    return 0;
}

/* Sample Input
3
3 4
1 0 0 0
0 0 0 0
0 0 2 -1
3 4
1 0 0 0
0 0 0 0
0 0 0 2
2 2
0 1
2 0

Sample Output
2
4
0

*/