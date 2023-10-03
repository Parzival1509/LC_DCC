// LC DCC 2023/09/18
// 1337. The K Weakest Rows in a Matrix
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rowStrengths;
        for(int i = 0; i < mat.size(); ++i) {
            int strength = accumulate(mat[i].begin(), mat[i].end(), 0);
            rowStrengths.push_back({strength, i});
        }
        
        sort(rowStrengths.begin(), rowStrengths.end());
        
        vector<int> result;
        for(int i = 0; i < k; ++i)
            result.push_back(rowStrengths[i].second);
        
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> mat[i][j];
        vector<int> ans = ob.kWeakestRows(mat, k);
        for(auto i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2

5 5 3
1 1 0 0 0
1 1 1 1 0
1 0 0 0 0
1 1 0 0 0
1 1 1 1 1

4 4 2
1 0 0 0
1 1 1 1
1 0 0 0
1 0 0 0


Sample Output:
2 0 3 
0 2 

*/