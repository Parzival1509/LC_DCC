// LC DCC 2024/04/18
// 463. Island Perimeter
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0, rows = grid.size(), cols = grid[0].size();
        
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    perimeter += 4;
                    if (r > 0 && grid[r-1][c] == 1)
                        perimeter -= 2;
                    if (c > 0 && grid[r][c-1] == 1)
                        perimeter -= 2;
                }
            }
        
        return perimeter;
    }
};  

int main() {
    int T;
    scanf("%d ", &T);
    Solution ob;
    while (T--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int> (c, 0));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> grid[i][j];

        cout << ob.islandPerimeter(grid) << endl;
    }

    return 0;
}

/* Sample Input
3
1 1
1
1 2
1 0
4 4
0 1 0 0
1 1 1 0
0 1 0 0
1 1 0 0

Sample Output
4
4
16

*/