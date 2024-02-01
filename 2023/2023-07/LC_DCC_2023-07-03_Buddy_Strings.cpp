// LC DCC 2023/07/03
// 859. Buddy Strings
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        vector<int> hsh1(26, 0), hsh2(26, 0);
        int ct = 0, unique = 0;
        for(char ch: s)
            hsh1[ch - 'a']++;

        for(char ch: goal)
            hsh2[ch - 'a']++;

        for(int i = 0; i < 26; i++) {
            if(hsh1[i] != hsh2[i])
                return false;
            if(hsh1[i] > 0) unique++;
        }

        for(int i = 0; i < s.size(); i++)
            if(s[i] != goal[i]) ct++;

        if(unique < s.size()) return ct < 3;
        return ct == 2;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        string s, goal;
        cin >> s >> goal;
        cout << ob.buddyStrings(s, goal) << endl;
    }
    return 0;
}

/* Sample Input:
3
ab ba
ab ab
aa aa

Sample Output:
true
false
true

*/