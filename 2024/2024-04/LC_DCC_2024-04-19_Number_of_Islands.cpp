// LC DCC 2024/04/19
// 200. Number of Islands
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
            return;
        
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        
        return numIslands;
    }
};

int main() {
    int T;
    scanf("%d ", &T);
    Solution ob;
    while (T--) {
        int r, c;
        cin >> r >> c;
        vector<vector<char>> grid(r, vector<char> (c, '0'));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> grid[i][j];

        cout << ob.numIslands(grid) << endl;
    }

    return 0;
}

/* Sample Input
2
4 5
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1

Sample Output
1
3

*/