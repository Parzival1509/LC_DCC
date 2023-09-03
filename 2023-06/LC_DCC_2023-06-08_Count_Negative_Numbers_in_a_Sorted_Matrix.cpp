// LC DCC 2023/06/08
// 1351. Count Negative Numbers in a Sorted Matrix
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = grid[0].size() - 1 - ans; j >= 0 && grid[i][j] < 0; j--)
                ans++;
            res += ans;
        }
        return res;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];

        cout << ob.countNegatives(grid) << endl;
    }
    return 0;
}

/* Sample Input:
2

4 4
4 3 2 -1
3 2 1 -1
1 1 -1 -2
-1 -1 -2 -3

2 2
3 2
1 0

Sample Output:
8
0 

*/