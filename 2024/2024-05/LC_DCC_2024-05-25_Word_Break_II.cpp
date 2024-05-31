// LC DCC 2024/05/25
// 140. Word Break II
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordBreakHelper(string& s, int start, unordered_set<string>& dict, unordered_map<int, vector<string>>& memo) {
        if (memo.find(start) != memo.end())
            return memo[start];

        vector<string> validSubstr;
        if (start == s.length())
            validSubstr.push_back("");

        for (int end = start + 1; end <= s.length(); ++end) {
            string prefix = s.substr(start, end - start);
            if (dict.find(prefix) != dict.end()) {
                vector<string> suffixes = wordBreakHelper(s, end, dict, memo);
                for (string& suffix : suffixes)
                    validSubstr.push_back(prefix + (suffix.empty() ? "" : " ") + suffix);
            }
        }
        memo[start] = validSubstr;

        return validSubstr;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, vector<string>> memo;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreakHelper(s, 0, dict, memo);
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        vector<string> wordDict(n, " ");
        for(auto &i: wordDict)
            cin >> i;
        vector<string> ans = ob.wordBreak(s, wordDict);
        for(auto i: ans)
            cout << i << endl;
        cout << endl;
    }

    return 0;
}

/* Sample Input
3
5 catsanddog
cat cats and sand dog
5 pineapplepenapple
apple pen applepen pine pineapple
5 catsandog
cat cats and sand dog

Sample Output
cat sand dog
cats and dog

pine apple pen apple
pine applepen apple
pineapple pen apple



*/