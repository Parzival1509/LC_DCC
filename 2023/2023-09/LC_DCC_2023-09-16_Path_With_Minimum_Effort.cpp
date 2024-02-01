// LC DCC 2023/09/16
// 1631. Path With Minimum Effort
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    // Dijkstra's Algorithm to find minimum effort
    int dijkstra(vector<vector<int>>& heights, vector<vector<int>>& effort) {
        int rows = heights.size();
        int cols = heights[0].size();

        // Priority queue to store {effort, {x, y}}
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}});
        effort[0][0] = 0;

        while(!pq.empty()) {
            auto current = pq.top().second;
            int cost = -pq.top().first;  // Effort for the current cell
            pq.pop();

            int x = current.first;
            int y = current.second;

            // Skip if we've already found a better effort for this cell
            if(cost > effort[x][y])
                continue;

            // Stop if we've reached the bottom-right cell
            if(x == rows - 1 && y == cols - 1)
                return cost;

            // Explore each direction (up, down, left, right)
            for(int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                // Check if the new coordinates are within bounds
                if(new_x < 0 || new_x >= rows || new_y < 0 || new_y >= cols)
                    continue;

                // Calculate new effort for the neighboring cell
                int new_effort = max(effort[x][y], abs(heights[x][y] - heights[new_x][new_y]));

                // Update effort if a lower effort is found for the neighboring cell
                if(new_effort < effort[new_x][new_y]) {
                    effort[new_x][new_y] = new_effort;
                    pq.push({-new_effort, {new_x, new_y}});
                }
            }
        }

        return effort[rows - 1][cols - 1];
    }

    // Function to find the minimum effort path
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> effort(105, vector<int> (105, INT_MAX));
        return dijkstra(heights, effort);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<int>> heights(rows, vector<int> (cols, 0));
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                cin >> heights[i][j];

        cout << ob.minimumEffortPath(heights) << endl;
    }

    return 0;
}

/* Sample Input:
3

3 3
1 2 2
3 8 2
5 3 5

3 3
1 2 3
3 8 4
5 3 5

5 5
1 2 1 1 1
1 2 1 2 1
1 2 1 2 1
1 2 1 2 1
1 1 1 2 1


Sample Output:
2
1
0

*/