// LC DCC 2024/04/20
// 1992. Find All Groups of Farmland
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int r, int c, int &r2, int &c2, vector<vector<int>>& land, vector<vector<int>>& vis) {
        int m = land.size(), n = land[0].size();
        vis[r][c] = 1;
        
        int dp1[4] = {-1, 1, 0, 0};
        int dp2[4] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nr = dp1[i] + r, nc = dp2[i] + c;
            
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && land[nr][nc] == 1 && !vis[nr][nc]) {
                r2 = max(r2, nr);
                c2 = max(c2, nc);
                solve(nr, nc, r2, c2, land, vis);
            }
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0)), ans;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && land[i][j] == 1) {
                    int r2 = i, c2 = j;
                    solve(i, j, r2, c2, land, vis);
                    ans.push_back({i, j, r2, c2});
                }
            }
        
        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> land(r, vector<int> (c, 0));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> land[i][j];

        vector<vector<int>> ans = ob.findFarmland(land);
        for(auto i: ans) {
            for(int e: i)
                cout << e << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input
3
1 1
0
2 2
1 1
1 1
3 3
1 0 0
0 1 1
0 1 1

Sample Output

0 0 1 1 

0 0 0 0 
1 1 2 2 


*/