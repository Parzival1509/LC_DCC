// LC DCC 2024/01/25
// 1143. Longest Common Subsequence
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Memoization
    int helper(int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
        if(n == 0 || m == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];

        // Last characters matched
        if(s1[n - 1] == s2[m - 1])
            return dp[n][m] = 1 + helper(n - 1, m - 1, s1, s2, dp);
        
        // Last characters did not match
        return dp[n][m] = max(helper(n - 1, m, s1, s2, dp), helper(n, m - 1, s1, s2, dp));
    }

    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        // return helper(n, m, s1, s2, dp);
        
        // Approach 2: Tabulation (Top-Down Approach)
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            
        return dp[n][m];
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << ob.longestCommonSubsequence(s1, s2) << endl;
    }

    return 0;
}

/* Sample Input
3
abcde ace
abc abc
abc def

Sample Output
3
3
0

*/