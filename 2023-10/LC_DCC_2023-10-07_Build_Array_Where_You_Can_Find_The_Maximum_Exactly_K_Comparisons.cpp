// LC DCC 2023/10/07
// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        int mod = 1e9 + 7;

        // // Approach 1: DP, T.C. = O(n * m * k), S.C. = O(m * k)
        // int dp[51][101][51], prefix[51][101][51];

        // for(int j = 0; j<= m; j++) {
        //     dp[1][j][1] = 1;
        //     prefix[1][j][1] = j;
        // }
        
        // for(int len = 2; len <= n; len++) {
        //     for(int mx = 1; mx <= m; mx++) {
        //         for(int cost = 1; cost <= k; cost++) {
        //             // In this first case, we can append any element from [1, mx] to the end of the array.
        //             dp[len][mx][cost] = (1LL * mx * dp[len-1][mx][cost]) % mod;
                    
        //             // In this second case, we can append the element "mx" to the end of the array. 
        //             // for (int i = 1; i < mx; i++) dp[len][mx][cost] += ways[len - 1][i][cost - 1];*/
        //             dp[len][mx][cost] = (dp[len][mx][cost] + prefix[len - 1][mx - 1][cost - 1]) % mod;
                    
        //             prefix[len][mx][cost] = (prefix[len][mx - 1][cost] + dp[len][mx][cost]) % mod;
        //         }
        //     }
        // }

        // return prefix[n][m][k];

        // Approach 2: Space Optimised DP, T.C. = O(n * m * k), S.C. = O(m * k)
        vector<vector<int>> dp, prevDp(m + 1, vector<int>(k + 1, 0));
        vector<vector<int>> prefix, prevPrefix(m + 1, vector<int>(k + 1, 0));

        for(int j = 1; j <= m; j++) {
            prevDp[j][1] = 1;
            prevPrefix[j][1] = j;
        }

        for(int _ = 2; _ <= n; _++) {
            dp.assign(m + 1, vector<int>(k + 1, 0));
            prefix.assign(m + 1, vector<int>(k + 1, 0));

            for(int maxNum = 1; maxNum <= m; maxNum++) {
                for(int cost = 1; cost <= k; cost++) {
                    dp[maxNum][cost] = ((long long)(maxNum) * prevDp[maxNum][cost]) % mod;
                    
                    if(maxNum > 1 && cost > 1)
                        dp[maxNum][cost] = (dp[maxNum][cost] + prevPrefix[maxNum - 1][cost - 1]) % mod;
                    
                    prefix[maxNum][cost] = (prefix[maxNum - 1][cost] + dp[maxNum][cost]) % mod;
                }
            }

            prevDp = dp;
            prevPrefix = prefix;
        }

        return prefix[m][k];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << ob.numOfArrays(n, m, k) << endl;
    }

    return 0;
}

/* Sample Input:
3
2 3 1
5 2 3
9 1 1

Sample Output:
6
0
1

*/