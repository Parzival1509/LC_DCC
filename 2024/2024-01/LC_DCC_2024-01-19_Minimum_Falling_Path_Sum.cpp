// LC DCC 2024/01/19
// 931. Minimum Falling Path Sum
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> prev(m, 0);
        for (int j = 0; j < m; ++j)
            prev[j] = matrix[0][j];

        for (int i = 1; i < n; ++i) {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; ++j) {
                int up = matrix[i][j] + prev[j];
                int left = 1e9, right = 1e9;
                if (j > 0)
                    left = matrix[i][j] + prev[j - 1];
                if (j < m - 1)
                    right = matrix[i][j] + prev[j + 1];
                curr[j] = min(up, min(left, right));
            }
            prev = curr;
        }

        int mini = 1e9;
        for (int j = 0; j < m; ++j)
            mini = min(mini, prev[j]);
        
        return mini;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];

        cout << ob.minFallingPathSum(matrix) << endl;
    }

    return 0;
}

/* Sample Input
2
2
-19 57
-40 -5
3
2 1 3
6 5 4
7 8 9

Sample Output
-59
13

*/