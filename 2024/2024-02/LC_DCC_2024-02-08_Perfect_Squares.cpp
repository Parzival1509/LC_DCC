// LC DCC 2024/02/08
// 279. Perfect Squares
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (dp[n] != INT_MAX) return dp[n];

        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++)
            ans = min(ans, solve(n - i * i, dp) + 1);

        return dp[n] = ans;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        return solve(n, dp);
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.numSquares(n) << endl;
    }

    return 0;
}

/* Sample Input
2
12
13

Sample Output
3
2

*/