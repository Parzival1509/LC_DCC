// LC DCC 2024/05/13
// 861. Score After Flipping Matrix
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = (1 << (m - 1)) * n;

        for(int j = 1; j < m; ++j) {
            int val = 1 << (m - 1 - j);
            int set = 0;
            for(int i = 0; i < n; ++i)
                if(grid[i][j] == grid[i][0])
                    set++;
            res += max(set, n - set) * val;
        }

        return res;
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
        cout << ob.matrixScore(grid) << endl;
    }

    return 0;
}

/* Sample Input
2
1 1
0
3 4
0 0 1 1
1 0 1 0
1 1 0 0

Sample Output
1
39

*/