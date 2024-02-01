// LC DCC 2023/09/23
// 1048. Longest String Chain
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    static bool cmp(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> ump;
        int ans = 0;

        for(string w: words) {
            int longest = 0;
            for(int i = 0; i < w.length(); i++) {
                string sub = w;
                sub.erase(i, 1);
                longest = max(longest, ump[sub] + 1);
            }
            ump[w] = longest;
            ans = max(ans, longest);
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<string> words(n, "");
        for(auto &i: words)
            cin >> i;
        cout << ob.longestStrChain(words) << endl;
    }

    return 0;
}

/* Sample Input:
3
6
a b ba bca bda bdca
5
xbc pcxbcf xb cxbc pcxbc
2
abcd dbqca

Sample Output:
4
5
1

*/