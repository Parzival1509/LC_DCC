// LC DCC 2024/01/28
// 1074. Number of Submatrices That Sum to Target
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), ct = 0;

        for (int row = 0; row < m; row++)
            for (int col = 1; col < n; col++)
                matrix[row][col] += matrix[row][col - 1];
        
        for (int c1 = 0; c1 < n; c1++) {
            for (int c2 = c1; c2 < n; c2++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;

                for (int row = 0; row < m; row++) {
                    sum += matrix[row][c2] - (c1 > 0 ? matrix[row][c1 - 1] : 0);
                    ct += mp[sum - target];
                    mp[sum]++;
                }
            }
        }

        return ct;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int m, n, target;
        cin >> m >> n >> target;
        vector<vector<int>> matrix(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];
        cout << ob.numSubmatrixSumTarget(matrix, target) << endl;
    }

    return 0;
}

/* Sample Input
3

3 3 0
0 1 0
1 1 1
0 1 0

2 2 0
1 -1
-1 1

1 1 0
904

Sample Output
4
5
0

*/