// LC DCC 2024/05/26
// 552. Student Attendance Record II
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mod = 1e9 + 7;

    int checkRecord(int n) {
        int dp[2][2][3] = {0};
        fill(&dp[0][0][0], &dp[0][0][0] + 6, 1);
        
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= 1; j++)
                for (int k = 0; k <= 2; k++) {
                    long long ans = dp[(i - 1) & 1][j][0];
                    ans += (k < 2 ? dp[(i - 1) & 1][j][k + 1] : 0);
                    ans += (j == 0 ? dp[(i - 1) & 1][j + 1][0] : 0);
                    
                    dp[i & 1][j][k] = ans % mod;
                }

        return dp[n & 1][0][0];
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin >> n;
        cout << ob.checkRecord(n) << endl;
    }

    return 0;
}

/* Sample Input
3
1
2
10101

Sample Output
3
8
183236316

*/