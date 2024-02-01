// LC DCC 2023/10/06
// 343. Integer Break
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxProduct(int n, vector<int>& dp) {
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];

        int maxProd = 0;
        for(int i = 1; i < n; ++i)
            maxProd = max(maxProd, max(i * (n - i), i * maxProduct(n - i, dp)));
        
        return dp[n] = maxProd;
    }
    
    int integerBreak(int n) {
        // // Approach 1: Memoization (Top-Down)
        // vector<int> dp(n + 1, -1);
        // return maxProduct(n, dp);

        // // Approach 2: Tabulation (Bottom-Up)
        // vector<int> dp(n + 1, 0);
        // dp[1] = 1;
        
        // for(int i = 2; i <= n; i++)
        //     for(int j = 1; j < i; j++)
        //         dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        
        // return dp[n];

        // // Approach 3: Greedy
        // if(n <= 3) return n - 1;

        // int ans = 1;
        // while(n > 4) {
        //     ans *= 3;
        //     n -= 3;
        // }
        // ans *= n;

        // return ans;

        // Approach 4: Mathematical Analysis
        if(n <= 3) return n - 1;

        int q = n / 3, r = n % 3;

        if(r == 0) return pow(3, q);
        if(r == 1) return pow(3, q - 1) * 4;
        return pow(3, q) * 2;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.integerBreak(n) << endl;
    }

    return 0;
}

/* Sample Input:
3
2 3 10

Sample Output:
1
2
36

*/