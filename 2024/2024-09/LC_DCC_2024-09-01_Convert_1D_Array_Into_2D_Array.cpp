// LC DCC 2024/09/01
// 2022. Convert 1D Array Into 2D Array
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz = original.size();
        if(sz != m * n) return {};

        vector<vector<int>> ans(m, vector<int>(n, 0));
        int ct = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                ans[i][j] = original[ct++];

        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int sz, m, n;
        cin >> sz >> m >> n;
        vector<int> original(sz, 0);
        for(int &i: original)
            cin >> i;

        vector<vector<int>> ans = ob.construct2DArray(original, m, n);
        for(auto row: ans) {
            for(auto e: row)
                cout << e << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input
3
4 2 2
1 2 3 4
3 1 3
1 2 3
2 1 1
1 2

Sample Output
1 2 
3 4 

1 2 3 



*/