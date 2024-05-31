// LC DCC 2024/05/14
// 1219. Path with Maximum Gold
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> row = {1, -1, 0, 0};
    vector<int> col = {0, 0, -1, 1};
    int maxGold = 0;

    int dfs(vector<vector<int>>& grid, int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)
            return 0;

        int curr = grid[x][y];
        grid[x][y] = 0;
        int localMaxGold = curr;

        for (int i = 0; i < 4; i++) {
            int newX = x + row[i];
            int newY = y + col[i];
            localMaxGold = max(localMaxGold, curr + dfs(grid, newX, newY, n, m));
        }

        grid[x][y] = curr;
        return localMaxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] != 0)
                    maxGold = max(maxGold, dfs(grid, i, j, n, m));

        return maxGold;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];
        cout << ob.getMaximumGold(grid) << endl;
    }

    return 0;
}

/* Sample Input
2

3 3
0 6 0
5 8 7
0 9 0

5 3
1 0 7
2 0 6
3 4 5
0 3 0
9 0 20

Sample Output
24
28

*/