// LC DCC 2024/04/02
// 205. Isomorphic Strings
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]])
                return false;
            
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }

        return true;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    // getchar();
    while(t--) {
        string s, t;
        // getline(cin, s);
        getline(cin >> ws, s);  // ws = white space
        // getchar();
        getline(cin, t);
        // getchar();
        // cout << s << endl << t << endl;
        if(ob.isIsomorphic(s, t)) cout << "true\n";
        else cout << "false\n";
        // cout << endl;
    }

    return 0;
}

/* Sample Input
3
egg egg
add add
foo
bar
paper
title

Sample Output
true
false
true

*/