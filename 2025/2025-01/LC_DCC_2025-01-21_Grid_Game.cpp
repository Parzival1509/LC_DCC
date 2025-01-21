// LC DCC 2025/01/21
// 2017. Grid Game
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottomSum = 0LL, ans = LONG_MAX;

        for (int i = 0; i < grid[0].size(); i++) {
            topSum -= grid[0][i];
            ans = min(ans, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }

        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(2, vector<int> (n, 0));
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];
        cout << ob.gridGame(grid) << endl;
    }

    return 0;
}

/* Sample Input
3
3
2 5 4
1 5 1
3
3 3 1
8 5 2
4
1 3 1 15
1 3 3 1

Sample Output
4
4
7

*/