// LC DCC 2023/04/14
// 516. Longest Palindromic Subsequence
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        // Base case: A single character is always a palindrome of length 1.
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        // Fill the dp table in bottom-up manner.
        for (int len = 2; len <= n; len++)
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                // If the two characters are the same, add 2 to the length of the palindrome.
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2; 
                // If the two characters are different, take the maximum of two subproblems.
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]); 
            }

        return dp[0][n-1]; 
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        string s;
        cin>>s;
        cout<<ob.longestPalindromeSubseq(s)<<endl;
    }
    return 0;
}

/* Sample Input:
2
bbbab
cbbd

Sample Output:
4
2

*/