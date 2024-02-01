// LC DCC 2023/12/01
// 1662. Check If Two String Arrays are Equivalent
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        for(auto i: word1)
            a += i;
        
        string b = "";
        for(auto i: word2)
            b += i;

        return a == b;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int a, b;
        cin >> a >> b;
        vector<string> word1(a, ""), word2(b, "");
        for(auto &i: word1)
            cin >> i;
        for(auto &i: word2)
            cin >> i;
        if(ob.arrayStringsAreEqual(word1, word2)) cout << "true";
        else cout << "false";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
2 2
ab c
a bc
2 2
a cb
a bc

Sample Output:
true
false

*/