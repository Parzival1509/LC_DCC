// LC DCC 2023/09/02
// 2707. Extra Characters in a String
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size(), max_val = n + 1;
        vector<int> dp(max_val, max_val);
        dp[0] = 0;

        unordered_set<string> dictionary_set(dictionary.begin(), dictionary.end());

        for(int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            for(int l = 1; l <= i; ++l) {
                if(dictionary_set.find(s.substr(i - l, l)) != dictionary_set.end())
                    dp[i] = min(dp[i], dp[i - l]);
            }
        }

        return dp[n];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        int n;
        cin >> n >> s;
        vector<string> dictionary(n, "");
        for(auto &i: dictionary)
            cin >> i;
        cout << ob.minExtraChar(s, dictionary) << endl;
    }

    return 0;
}

/* Sample Input:
2
3 leetscode
leet code leetcode
2 sayhelloworld
hello world

Sample Output:
1
3

*/