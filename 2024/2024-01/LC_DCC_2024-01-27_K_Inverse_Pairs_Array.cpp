// LC DCC 2024/01/27
// 629. K Inverse Pairs Array
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {1};

        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= k; j++)
                for (int x = 0; x <= min(j, i - 1); x++)
                    if (j - x >= 0)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % 1000000007;

        return dp[n][k];
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << ob.kInversePairs(n, k) << endl;
    }

    return 0;
}

/* Sample Input
2
3 0
3 1

Sample Output
1
2

*/