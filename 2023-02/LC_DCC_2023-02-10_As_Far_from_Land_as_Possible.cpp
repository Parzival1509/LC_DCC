// LC DCC 2023/02/10
// 1162. As Far from Land as Possible
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:    
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        // Although it's a square matrix, using different variable for readability.
        int cols = grid[0].size();

        // Maximum manhattan distance possible + 1.
        const int MAX_DISTANCE = rows + cols + 1;
        
        // First pass: check for left and top neighbours
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j]) {
                    // Distance of land cells will be 0.
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = MAX_DISTANCE;
                    // Check left and top cell distances if they exist and update the current cell distance.
                    grid[i][j] = min(grid[i][j], min(i > 0? grid[i - 1][j] + 1: MAX_DISTANCE,
                                                     j > 0? grid[i][j - 1] + 1: MAX_DISTANCE));
                }
            }
        }

        // Second pass: check for right and bottom neighbours.
        int ans = INT_MIN;
        for(int i = rows - 1; i >= 0; i--) {
            for(int j = cols - 1; j >= 0; j--) {
                // Check the right and bottom cell distances if they exist and update the current cell distance.
                grid[i][j] = min(grid[i][j], min(i < rows - 1? grid[i + 1][j] + 1: MAX_DISTANCE,
                                                 j < cols - 1? grid[i][j + 1] + 1: MAX_DISTANCE));
                ans = max(ans, grid[i][j]);
            }
        }
        
        // If ans is 1, it means there is no water cell,
        // If ans is MAX_DISTANCE, it implies no land cell.
        return (ans==0 || ans==MAX_DISTANCE)? -1: ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> grid(n, vector<int> (n, 0));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>grid[i][j];
        cout<<ob.maxDistance(grid)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3
1 0 1
0 0 0
1 0 1
3
1 0 0
0 0 0
0 0 0

Sample Output:
2
4

*/