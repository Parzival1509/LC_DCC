// LC DCC 2023/09/03
// 62. Unique Paths
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int uniquePaths(int m, int n) {
        // // Approach 1: Tabulation, T.C. = O(m * n), S.C. = O(m * n);=
        // int dp[m][n];
        // for(int i = 0; i < m; i++)
        //     for(int j = 0; j < n; j++)
        //         if(i == 0 || j == 0)
        //             dp[i][j] = 1;
        //         else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        
        // return dp[m - 1][n - 1];

        // Approach 2: T.C. = O(m), S.C. = O(1)
        int N = m + n - 2, r = m - 1;
        double res = 1;
        for(int i = 1; i <= r; i++)
            res = res * (N - r + i) / i;
        
        return (int)res;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int m, n;
        cin >> m >> n;
        cout << ob.uniquePaths(m, n) << endl;
    }

    return 0;
}

/* Sample Input:
2
3 7
3 2

Sample Output:
28
3

*/