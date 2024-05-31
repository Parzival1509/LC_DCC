// LC DCC 2024/05/24
// 1255. Maximum Score Words Formed by Letters
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtracking(vector<string>& words, vector<int>& score, vector<int>& count, vector<int>& lettersCount, int pos, int temp, int& ans) {
        for (int i = 0; i < 26; i++)
            if (lettersCount[i] > count[i])
                return;

        ans = max(ans, temp);
        for (int i = pos; i < words.size(); i++) {
            for (auto& c : words[i]) {
                lettersCount[c - 'a']++;
                temp += score[c - 'a'];
            }
            backtracking(words, score, count, lettersCount, i + 1, temp, ans);
            for (auto& c : words[i]) {
                lettersCount[c - 'a']--;
                temp -= score[c - 'a'];
            }
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0), lettersCount(26, 0);
        for (auto& c : letters)
            count[c - 'a']++;
        int ans = 0;
        backtracking(words, score, count, lettersCount, 0, 0, ans);

        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int w, l;
        cin >> w >> l;
        vector<string> words(w, " ");
        for(auto &i: words)
            cin >> i;
        vector<char> letters(l, 'a');
        for(auto &i: letters)
            cin >> i;
        vector<int> score(26, 0);
        for(int &i: score)
            cin >> i;
        cout << ob.maxScoreWords(words, letters, score) << endl;
    }

    return 0;
}

/* Sample Input
3
4 9
dog cat dad good
aacdddgoo
1 0 9 5 0 0 3 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0
4 7
xxxz ax bx cx
zabcxxx
4 4 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 5 0 10
1 6
leetcode
letcod
0 0 1 1 1 0 0 0 0 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0

Sample Output
23
27
0

*/