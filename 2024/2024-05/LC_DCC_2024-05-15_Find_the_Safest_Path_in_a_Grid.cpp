// LC DCC 2024/05/15
// 2812. Find the Safest Path in a Grid
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> row = {0, 0, -1, 1};
    vector<int> col = {-1, 1, 0, 0};

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& score, int n) {
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) {
                    score[i][j] = 0;
                    q.push({i, j});
                }

        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second, s = score[x][y];
            for (int i = 0; i < 4; i++) {
                int newX = x + row[i];
                int newY = y + col[i];
                if (newX >= 0 && newX < n && newY >= 0 && newY < n &&
                    score[newX][newY] > 1 + s) {
                    score[newX][newY] = 1 + s;
                    q.push({newX, newY});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return 0;

        vector<vector<int>> score(n, vector<int>(n, INT_MAX));
        bfs(grid, score, n);
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({score[0][0], {0, 0}});
        while (!pq.empty()) {
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();
            if (temp.first == n - 1 && temp.second == n - 1)
                return safe;
            
            vis[temp.first][temp.second] = true;
            for (int i = 0; i < 4; i++) {
                int newX = temp.first + row[i];
                int newY = temp.second + col[i];
                if (newX >= 0 && newX < n && newY >= 0 && newY < n &&
                    !vis[newX][newY]) {
                    int s = min(safe, score[newX][newY]);
                    pq.push({s, {newX, newY}});
                    vis[newX][newY] = true;
                }
            }
        }

        return -1;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];
        cout << ob.maximumSafenessFactor(grid) << endl;
    }

    return 0;
}

/* Sample Input
3
3
1 0 0
0 0 0
0 0 1
3
0 0 1
0 0 0
0 0 0
4
0 0 0 1
0 0 0 0
0 0 0 0
1 0 0 0

Sample Output
0
2
2

*/