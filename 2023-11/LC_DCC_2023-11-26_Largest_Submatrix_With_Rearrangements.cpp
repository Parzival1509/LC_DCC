// LC DCC 2023/11/26
// 1727. Largest Submatrix With Rearrangements
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++)
                if(matrix[row][col] != 0 && row > 0)
                    matrix[row][col] += matrix[row-1][col];
            
            vector<int> currRow = matrix[row];
            sort(currRow.begin(), currRow.end(), greater<int>());
            for(int i = 0; i < n; i++)
                ans = max(ans, currRow[i] * (i+1));
        }

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
        vector<vector<int>> matrix(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];
        cout << ob.largestSubmatrix(matrix) << endl;
    }

    return 0;
}

/* Sample Input:
3

3 3
0 0 1
1 1 1
1 0 1

1 5
1 0 1 0 1

2 3
1 1 0
1 0 1


Sample Output:
4
3
2

*/