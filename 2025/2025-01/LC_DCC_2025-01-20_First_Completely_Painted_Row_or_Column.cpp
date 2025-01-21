// LC DCC 2025/01/20
// 2661. First Completely Painted Row or Column
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), total = m * n;
        vector<int> rows(m, 0), cols(n, 0);

        vector<pair<int, int>> pos(total, {0, 0});
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int e = mat[i][j];
                pos[e - 1] = {i, j};
            }
        }

        for (int i = 0; i < total; i++) {
            int r = ++rows[pos[arr[i] - 1].first];
            int c = ++cols[pos[arr[i] - 1].second];

            if (r == n || c == m)
                return i;
        }

        return 1;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> mat(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> mat[i][j];
        vector<int> arr(m * n, 0);
        for(int i = 0; i < m * n; i++)
            cin >> arr[i];
        cout << ob.firstCompleteIndex(arr, mat) << endl;
    }

    return 0;
}

/* Sample Input
3

2 3
4 3 5
1 2 6
1 4 5 2 6 3

2 2
1 4
2 3
1 3 4 2

3 3
3 2 5
1 4 6
8 7 9
2 8 7 4 1 3 5 6 9

Sample Output
1
2
3

*/