// LC DCC 2023/12/02
// 1160. Find Words That Can Be Formed by Characters
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool canForm(const std::string& word, std::vector<int>& counts) {
        vector<int> c(26, 0);
        for(char ch: word) {
            int x = ch - 'a';
            c[x]++;
            if(c[x] > counts[x])
                return false;
        }

        return true;
    }

    int countCharacters(vector<string>& words, string chars) {
        vector<int> counts(26, 0);
        for(char ch: chars)
            counts[ch - 'a']++;

        int ans = 0;
        for(string& word: words) {
            if(canForm(word, counts))
                ans += word.length();
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string chars;
        int n;
        cin >> chars >> n;
        vector<string> words(n, "");
        for(auto &i: words)
            cin >> i;
        cout << ob.countCharacters(words, chars) << endl;
    }

    return 0;
}

/* Sample Input:
2
atach 4
cat bt hat tree
welldonehoneyr 3
hello world leetcode

Sample Output:
true
false

*/