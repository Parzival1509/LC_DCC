// LC DCC 2024/02/11
// 1463. Cherry Pickup II
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickupHelp(int i, int j1, int j2, vector<vector<int>>& g, vector<vector<vector<int>>>& dp) {
        if (i >= g.size() || j1 < 0 || j2 < 0 || j1 >= g[0].size() || j2 >= g[0].size())
            return 0;
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = 0;
        for (int w1 : {-1, 0, 1})
            for (int w2 : {-1, 0, 1})
                maxi = max(maxi, cherryPickupHelp(i + 1, j1 + w1, j2 + w2, g, dp));

        return dp[i][j1][j2] = g[i][j1] + (j1 != j2 ? g[i][j2] : 0) + maxi;
    }

    int cherryPickup(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        // // Approach 1: Top Down, S.C. = O(N*M*M)
        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));

        // return cherryPickupHelp(0, 0, m - 1, g, dp);

        // // Approach 2: Bottom Up (3D DP), S.C. = O(N*M*M)
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (m + 1, 0)));
        
        // for (int i = n - 1; i >= 0; i--) {
        //     for (int j1 = 0; j1 < m; j1++) {
        //         for (int j2 = m - 1; j2 >= 0; j2--) {

        //             int maxi = 0;

        //             for (int w1 : {-1, 0, 1}) {
        //                 for (int w2 : {-1, 0, 1}) {
        //                     if (j1 + w1 >= 0 && j2 + w2 >= 0)
        //                         maxi = max(maxi, dp[i + 1][j1 + w1][j2 + w2]);
        //                 }
        //             }

        //             dp[i][j1][j2] = g[i][j1] + (j1 != j2 ? g[i][j2] : 0) + maxi;
        //         }
        //     }
        // }

        // return dp[0][0][m - 1];

        // Approach 3: Bottom Up / Tabulation (Space-Optmized 2D DP), S.C. = O(M*M);
        vector<vector<int>> nxt(m + 1, vector<int> (m + 1, 0)), cur(m + 1, vector<int> (m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = m - 1; j2 >= 0; j2--) {
                    int maxi = 0;

                    for (int w1 : {-1, 0, 1})
                        for (int w2 : {-1, 0, 1})
                            if (j1 + w1 >= 0 && j2 + w2 >= 0)
                                maxi = max(maxi, nxt[j1 + w1][j2 + w2]);

                    cur[j1][j2] = g[i][j1] + (j1 != j2 ? g[i][j2] : 0) + maxi;
                }
            }
            nxt = cur;
        }

        return nxt[0][m - 1];
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int> (c, 0));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> grid[i][j];

        cout << ob.cherryPickup(grid) << endl;
    }

    return 0;
}

/* Sample Input
2

4 3
3 1 1
2 5 1
1 5 5
2 1 1

5 7
1 0 0 0 0 0 1
2 0 0 0 0 3 0
2 0 9 0 0 0 0
0 3 0 5 4 0 0
1 0 2 3 0 0 6


Sample Output
24
28

*/