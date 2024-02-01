// LC DCC 2024/01/12
// 1704. Determine if String Halves Are Alike
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int ct = 0, n = s.size();
        for(int i = 0; i < n / 2; i++)
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                ct++;
        
        for(int i = n / 2; i < n; i++)
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                ct--;
        
        return ct == 0;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(ob.halvesAreAlike(s)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}

/* Sample Input
2
book
textbook

Sample Output
true
false

*/