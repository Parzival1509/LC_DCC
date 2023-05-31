// LC DCC 2023/04/22
// 1312. Minimum Insertion Steps to Make a String Palindrome
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // Approach 1: Memoization, T.C. = O(N^2), S.C. = O(N)
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> memo(2, vector<int> (n, 0));
        for (int i = n - 2; i >= 0; --i)
            for (int j = i + 1; j < n; ++j) {
                int row = i % 2;
                int other = (i + 1) % 2;
                memo[row][j] = 1 + min(memo[other][j], memo[row][j - 1]);
                if (s[i] == s[j]) memo[row][j] = min(memo[row][j], memo[other][j - 1]);
            }
        return memo[0][n - 1];
    }

    // // Approach 2: LCS
    // int lcs(string& s1, string& s2, int m, int n) {
    //     vector<int> dp(n + 1), dpPrev(n + 1);
    //     for(int i = 0; i <= m; i++) {
    //         for(int j = 0; j <= n; j++) {
    //             // One of the two strings is empty.
    //             if(i == 0 || j == 0) dp[j] = 0;
    //             else if(s1[i - 1] == s2[j - 1]) dp[j] = 1 + dpPrev[j - 1];
    //             else dp[j] = max(dpPrev[j], dp[j - 1]);
    //         }
    //         dpPrev = dp;
    //     }
    //     return dp[n];
    // }

    // int minInsertions(string s) {
    //     int n = s.length();
    //     string sReverse = s;
    //     reverse(sReverse.begin(), sReverse.end());
    //     return n - lcs(s, sReverse, n, n);
    // }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        string s;
        cin>>s;
        cout<<ob.minInsertions(s)<<endl;
    }
    return 0;
}

/* Sample Input:
3
zzazz
mbadm
leetcode

Sample Output:
0
2
5

*/