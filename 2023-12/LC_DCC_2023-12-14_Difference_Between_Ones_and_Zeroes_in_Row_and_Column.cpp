// LC DCC 2023/12/14
// 2482. Difference Between Ones and Zeros in Row and Column
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> onesRow(m, 0), onesCol(n, 0);

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }

        vector<vector<int>> diff(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                diff[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - n - m;

        return diff;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];

        vector<vector<int>> ans = ob.onesMinusZeros(grid);
        for(auto row: ans) {
            for(int e: row)
                cout << e << ' ';
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}

/* Sample Input:
2

3 3
0 1 1
1 0 1
0 0 1

2 3
1 1 1
1 1 1


Sample Output:
0 0 4 
0 0 4 
-2 -2 2 

5 5 5 
5 5 5 


*/