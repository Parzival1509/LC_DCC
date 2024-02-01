// LC DCC 2023/06/29
// 864. Shortest Path to Get All Keys
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // // Approach 1: BFS Bit Manipulation
    // int shortestPathAllKeys(vector<string>& grid) {
    //     int m = grid.size(), n = grid[0].size();

    //     unordered_map<char, int> key_bit;
    //     int bit_start = 0;
    //     for (int i = 0; i < m; i++)
    //         for (int j = 0; j < n; j++)
    //             if (islower(grid[i][j]))
    //                 key_bit[grid[i][j]] = bit_start++;
        
    //     int mask_end = (1 << bit_start) - 1;
    //     int mask_size = (1 << bit_start);

    //     vector<vector<vector<bool>>> memo(m, vector<vector<bool>> (n, vector<bool>(mask_size, false)));
    //     vector<int> start;
    //     for (int i = 0; i < m; i++)
    //         for (int j = 0; j < n; j++)
    //             if (grid[i][j] == '@')
    //                 start = {i, j, 0}; // 0 denoting no key state

    //     queue<vector<int>> q;
    //     q.push(start);
    //     int step = 0;
    //     while (!q.empty()) {
    //         int size = q.size();
    //         for (int k = 0; k < size; k++) {
    //             int row = q.front()[0], col = q.front()[1], mask = q.front()[2];
    //             q.pop();
               
    //             if (row < 0 || row >= m || col < 0 || col >= n) continue;
    //             if (grid[row][col] == '#') continue;
    //             if (isupper(grid[row][col]))
    //                 if ((mask & (1 << key_bit[tolower(grid[row][col])])) == 0)
    //                     continue;

    //             if (islower(grid[row][col]))
    //                 mask = mask | (1 << key_bit[grid[row][col]]);
    //             if (mask == mask_end) return step;
                
    //             if (memo[row][col][mask]) continue;
    //             memo[row][col][mask] = true;
               
    //             q.push({row + 1, col, mask});
    //             q.push({row - 1, col, mask});
    //             q.push({row, col + 1, mask});
    //             q.push({row, col - 1, mask});
    //         }
    //         step++;
    //     }

    //     return -1;
    // }

    // Approach 2: Map
    void find(int i, int j, vector<string>& grid, string& s, vector<vector<unordered_set<string>>>& vis, queue<pair<pair<int, int>, string>>& qmt, int m, int n) {
        if(i >= m || i < 0 || j >= n || j < 0) return;
        if(grid[i][j] == '#') return;
        
        if(grid[i][j] >= 'a' && grid[i][j] <= 'z') {
            string tmp = s;
            int flg = 0;
            for(auto& p: tmp)
                if(p == grid[i][j]) flg = 1;
            
            if(flg == 0)
            tmp.push_back(grid[i][j]);
            sort(tmp.begin(), tmp.end());
            if(vis[i][j].find(tmp) != vis[i][j].end()) return;

            vis[i][j].insert(tmp);
            qmt.push({{i, j}, tmp});
            return;
        }

        if(grid[i][j] == '.' || grid[i][j] == '@') {
            string tmp = s;
            if(vis[i][j].find(tmp) != vis[i][j].end()) return;

            vis[i][j].insert(tmp);
            qmt.push({{i, j}, tmp});
            return;
        }

        if(grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
            string tmp = s;
            char t = grid[i][j]+32;
            int flg = 0;
            for(auto& p: tmp)
                if(p == t) flg = 1;

            if(flg == 0) return;
            if(vis[i][j].find(tmp) != vis[i][j].end()) return;

            vis[i][j].insert(tmp);
            qmt.push({{i, j}, tmp});
        }
    }
    
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size(), cntk = 0, strti, strtj;
        vector<vector<unordered_set<string>>> mp(m, vector<unordered_set<string>> (n, unordered_set<string> {}));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '@') {
                    strti = i;
                    strtj = j;
                }
                if(grid[i][j] >= 'a' && grid[i][j] <= 'z') cntk++;
            }
        }
        int ans = -1;
        queue<pair<pair<int, int>, string>> qmt;
        qmt.push({{strti, strtj}, ""});
        while(qmt.size() > 0) {
            ans++;
            int sz = qmt.size();
            for(int k = 0; k < sz; k++) {
                pair<pair<int, int>, string> p = qmt.front();
                qmt.pop();
                int i = p.first.first, j = p.first.second;
                string s = p.second;
                if(s.size() == cntk) return ans;

                find(i + 1, j, grid, s, mp, qmt, m, n);
                find(i - 1, j, grid, s, mp, qmt, m, n);
                find(i, j + 1, grid, s, mp, qmt, m, n);
                find(i, j - 1, grid, s, mp, qmt, m, n);
            }
        }

        return -1;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<string> grid;
        for(int i = 0; i < m; i++) {
            string tmp;
            cin >> tmp;
            grid.push_back(tmp);
        }

        cout << ob.shortestPathAllKeys(grid) << endl;
    }
    return 0;
}

/* Sample Input:
3

3 5
@.a..
###.#
b.A.B

3 5
@..aA
..B#.
....b

1 3
@Aa

Sample Output:
8
6
-1

*/