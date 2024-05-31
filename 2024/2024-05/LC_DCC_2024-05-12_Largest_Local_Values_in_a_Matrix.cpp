// LC DCC 2024/05/12
// 2373. Largest Local Values in a Matrix
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int i = 1; i < n - 1; ++i) {
            for(int j = 1; j < n - 1; ++j) {
                int temp = 0;

                for(int k = i - 1; k <= i + 1; ++k)
                    for(int l = j - 1; l <= j + 1; ++l)
                        temp = max(temp, grid[k][l]);

                grid[i - 1][j - 1] = temp;
            }
        }

        grid.resize(n - 2);
        for (int i = 0; i < grid.size(); ++i)
            grid[i].resize(n - 2);

        return grid;
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

        vector<vector<int>> ans = ob.largestLocal(grid);
        for(auto r: ans) {
            for(int e: r)
                cout << e << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
4
9 9 8 1
5 6 2 5
8 2 6 4
6 2 2 2
5
1 1 1 1 1
1 1 1 1 1
1 1 2 1 1
1 1 1 1 1
1 1 1 1 1

Sample Output
9 9 
8 6 

2 2 2 
2 2 2 
2 2 2 


*/