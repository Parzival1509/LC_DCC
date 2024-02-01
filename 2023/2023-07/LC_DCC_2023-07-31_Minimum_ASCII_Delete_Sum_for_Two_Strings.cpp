// LC DCC 2023/07/31
// 712. Minimum ASCII Delete Sum for Two Strings
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

        for(int i = 1; i <= m; i++)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];

        for(int j = 1; j <= n; j++)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        
        return dp[m][n];
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << ob.minimumDeleteSum(s1, s2) << endl;
    }
    
    return 0;
}

/* Sample Input:
2
sea eat
delete leet

Sample Output:
231
403

*/