// LC DCC 2023/06/13
// 2352. Equal Row and Column Pairs
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> hsh;
        int ans = 0, n = grid.size();
        for(int i = 0; i < n; i++)
            hsh[grid[i]]++;
        
        for(int j = 0; j < n; j++) {
            vector<int> curr;
            for(int i = 0; i < n; i++)
                curr.emplace_back(grid[i][j]);
            ans += hsh[curr];
        }

        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];
        cout << ob.equalPairs(grid) << endl;
    }
    return 0;
}

/* Sample Input:
3
3
3 2 1
1 7 6
2 7 7
4
3 1 2 2
1 4 4 5
2 4 2 2
2 4 2 2
2
13 13
13 13

Sample Output:
1
3
4

*/