// LC DCC 2024/06/03
// 2486. Append Characters to String to Make Subsequence
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_index = 0, t_index = 0;
        int s_length = s.length(), t_length = t.length();
    
        while (s_index < s_length && t_index < t_length) {
            if (s[s_index] == t[t_index])
                t_index++;
            s_index++;
        }
    
        return t_length - t_index;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        string s, t;
        cin >> s >> t;
        cout << ob.appendCharacters(s, t) << endl;
    }

    return 0;
}

/* Sample Input
3
coaching coding
abcde a
z abcde

Sample Output
4
0
5

*/