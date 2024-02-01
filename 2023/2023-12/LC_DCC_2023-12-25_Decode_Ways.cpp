// LC DCC 2023/12/25
// 91. Decode Ways
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int numDecodingsTopDown(string s, int index, vector<int>& memo) {
        if(index == s.length()) return 1;
        if(s[index] == '0') return 0;

        if(memo[index] != -1) return memo[index];

        int ways = numDecodingsTopDown(s, index + 1, memo);
        if(index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')))
            ways += numDecodingsTopDown(s, index + 2, memo);

        return memo[index] = ways;;
    }

    int numDecodings(string s) {
        // Approach 1: Top-Down DP
        vector<int> memo(s.length(), -1);
        return numDecodingsTopDown(s, 0, memo);

        // // Approach 2: Bottom-Up DP
        // int n = s.length();
        // if(n == 0 || s[0] == '0')
        //     return 0;

        // vector<int> dp(2, 0);
        // dp[0] = 1;
        // dp[1] = 1;

        // for(int i = 1; i < n; ++i) {
        //     int ways = 0;
        //     if(s[i] != '0')
        //         ways += dp[1];

        //     if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
        //         ways += dp[0];

        //     dp[0] = dp[1];
        //     dp[1] = ways;
        // }

        // return dp[1];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.numDecodings(s) << endl;
    }

    return 0;
}

/* Sample Input:
3
12
226
06

Sample Output:
2
3
0

*/