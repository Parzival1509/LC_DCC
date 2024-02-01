// LC DCC 2023/08/17
// 542. 01 Matrix
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size(), INF = m + n;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(mat[r][c] == 0) continue;

                int top = INF, left = INF;
                if(r - 1 >= 0) top = mat[r - 1][c];
                if(c - 1 >= 0) left = mat[r][c - 1];

                mat[r][c] = min(top, left) + 1;
            }
        }

        for(int r = m - 1; r >= 0; r--) {
            for(int c = n - 1; c >= 0; c--) {
                if(mat[r][c] == 0) continue;

                int bottom = INF, right = INF;
                if(r + 1 < m) bottom = mat[r + 1][c];
                if(c + 1 < n) right = mat[r][c + 1];
                
                mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
            }
        }

        return mat;
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

        vector<vector<int>> ans = ob.updateMatrix(mat);
        for(auto r: mat) {
            for(int e: r)
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
0 0 0
0 1 0
0 0 0

3 3
0 0 0
0 1 0
1 1 1

Sample Output:
0 0 0 
0 1 0 
0 0 0 

0 0 0 
0 1 0 
1 2 1 


*/