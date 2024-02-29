// LC DCC 2024/02/05
// 387. First Unique Character in a String
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26, 0);
        for(int i = 0; i < s.size(); i++)
            f[s[i] - 'a']++;

        for(int i = 0; i < s.size(); i++)
            if(f[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.firstUniqChar(s) << endl;
    }

    return 0;
}

/* Sample Input
3
leetcode
loveleetcode
aabb

Sample Output
0
2
-1

*/