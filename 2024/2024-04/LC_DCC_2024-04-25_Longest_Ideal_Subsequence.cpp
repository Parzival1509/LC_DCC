// LC DCC 2024/04/25
// 2370. Longest Ideal Subsequence
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[27] = {0};
        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            char cc = s[i];
            int idx = cc - 'a', maxi = INT_MIN;
            int left = max((idx - k), 0);
            int right = min((idx + k), 26);

            for (int j = left; j <= right; j++)
                maxi = max(maxi, dp[j]);

            dp[idx] = maxi + 1;
        }

        int mx = INT_MIN;
        for (int i = 0; i < 27; i++)
            if (dp[i] > mx)
                mx = dp[i];

        return mx;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        string s;
        int k;
        cin >> s >> k;
        cout << ob.longestIdealString(s, k) << endl;
    }

    return 0;
}

/* Sample Input
2
acfgbd 2
abcd 3

Sample Output
4
4

*/