// LC DCC 2023/05/21
// 934. Shortest Bridge
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // // Approach 1:
    // vector<pair<int, int>> first, second;
    
    // void mark(int i, int j, int no, vector<vector<int>>& grid) {
    //     if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
    //        return;
    //     grid[i][j] = no;

    //     if(no == 2) first.push_back({i, j});
    //     else second.push_back({i, j});

    //     mark(i+1, j, no, grid);
    //     mark(i-1, j, no, grid);
    //     mark(i, j+1, no, grid);
    //     mark(i, j-1, no, grid);
    // }
    
    
    // int shortestBridge(vector<vector<int>>& grid) {
    //     int count = 2;
    //     for(int i = 0; i < grid.size(); i++)
    //         for(int j = 0; j < grid[0].size(); j++)
    //             if(grid[i][j] == 1) {
    //                 mark(i, j, count, grid);
    //                 count++;
    //             }

    //     int ans = 1000000;
    //     for(int i = 0; i < first.size(); i++)
    //         for(int j = 0; j < second.size(); j++)
    //             ans = min(abs(first[i].first - second[j].first) + abs(first[i].second - second[j].second) - 1, ans);
    //     return ans;
    // }

    // Approach 2:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        bool found = false;
        // Step 1: Find the first island and mark its cells with a unique value
        for(int i = 0; i < m && !found; i++)
            for(int j = 0; j < n && !found; j++)
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, m, n, q);
                    found = true;
                }
        
        // Step 2: Expand the first island until reaching the second island
        int steps = 0;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];
                    
                    if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || grid[newRow][newCol] == 2)
                        continue;
                    if(grid[newRow][newCol] == 1)
                        return steps;

                    grid[newRow][newCol] = 2;
                    q.push({newRow, newCol});
                }
            }
            steps++;
        }
        return -1; // If the second island is not found, return -1
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int m, int n, queue<pair<int, int>>& q) {
        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != 1)
            return;
        
        grid[row][col] = 2; // Mark the cell as visited
        q.push({row, col}); // Add the cell to the queue for expansion
        
        // Recursively explore the neighboring cells
        dfs(grid, row - 1, col, m, n, q);
        dfs(grid, row + 1, col, m, n, q);
        dfs(grid, row, col - 1, m, n, q);
        dfs(grid, row, col + 1, m, n, q);
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> grid (n, vector<int> (n, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin>>grid[i][j];
        cout<<ob.shortestBridge(grid)<<endl;
    }
    return 0;
}

/* Sample Input:
3
2
0 1
1 0
3
0 1 0
0 0 0
0 0 1
5
1 1 1 1 1
1 0 0 0 1
1 0 1 0 1
1 0 0 0 1
1 1 1 1 1

Sample Output:
1
2
1

*/