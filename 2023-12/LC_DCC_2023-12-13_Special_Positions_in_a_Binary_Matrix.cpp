// LC DCC 2023/12/13
// 1582. Special Positions in a Binary Matrix
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowCount(m, 0), colCount(n, 0);

        for(int row = 0; row < m; row++)
            for(int col = 0; col < n; col++)
                if(mat[row][col] == 1) {
                    rowCount[row]++;
                    colCount[col]++;
                }

        int ans = 0;
        for(int row = 0; row < m; row++)
            for(int col = 0; col < n; col++)
                if(mat[row][col] == 1)
                    if(rowCount[row] == 1 && colCount[col] == 1)
                        ans++;

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> mat(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> mat[i][j];

        cout << ob.numSpecial(mat) << endl;
    }

    return 0;
}

/* Sample Input:
2

3 3
1 0 0
0 0 1
1 0 0

3 3
1 0 0
0 1 0
0 0 1


Sample Output:
1
3

*/