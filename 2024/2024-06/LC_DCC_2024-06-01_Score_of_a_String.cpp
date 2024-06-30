// LC DCC 2024/06/01
// 3110. Score of a String
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for(int i = 1; i < s.size(); i++)
            ans += abs(s[i] - s[i - 1]);
        
        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        string s;
        cin >> s;
        cout << ob.scoreOfString(s) << endl;
    }

    return 0;
}

/* Sample Input
2
hello
zaz

Sample Output
13
50

*/