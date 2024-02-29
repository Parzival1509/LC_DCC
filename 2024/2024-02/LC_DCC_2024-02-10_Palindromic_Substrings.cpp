// LC DCC 2024/02/10
// 647. Palindromic Substrings
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int palindromeCount(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
            ++count;
        }

        return count;
    }

    int countSubstrings(string s) {
        int n = s.length(), ans = 0;
        
        // // Approach 1: Expand the Middle, T.C. = O(N^2), S.C. = O(1)
        // for (int i = 0; i < n; ++i) {
        //     int even = palindromeCount(s, i, i + 1);
        //     int odd = palindromeCount(s, i, i);
        //     ans += even + odd;
        // }

        // Approach 2: DP, T.C. = O(N^2), S.C. = O(N^2)
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                if (s[i] == s[i + len - 1] && (len <= 2 || palindrome[i + 1][i + len - 2])) {
                    palindrome[i][i + len - 1] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.countSubstrings(s) << endl;
    }

    return 0;
}

/* Sample Input
2
abc
aaa

Sample Output
3
6

*/