// LC DCC 2023/12/16
// 242. Valid Anagram
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hs(26, 0), ht(26, 0);
        for(auto c: s)
            hs[c - 'a']++;
        
        for(auto c: t)
            ht[c - 'a']++;

        for(int i = 0; i < 26; i++)
            if(hs[i] != ht[i]) return false;

        return true;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s, t;
        cin >> s >> t;
        if(ob.isAnagram(s, t)) cout << "true ";
        else cout << "false ";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
anagram nagaram
car rat

Sample Output:
true 
false 

*/