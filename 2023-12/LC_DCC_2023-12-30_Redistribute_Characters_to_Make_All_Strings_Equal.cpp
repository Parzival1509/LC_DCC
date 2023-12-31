// LC DCC 2023/12/30
// 1897. Redistribute Characters to Make All Strings Equal
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> hsh(26, 0);
        for(auto w: words)
            for(char c: w)
                hsh[c - 'a']++;

        for(int i: hsh)
            if(i % n != 0) return false;

        return true;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<string> words(n, "");
        for(auto &i: words)
            cin >> i;
        if(ob.makeEqual(words)) cout << "true";
        else cout << "false";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
3
abc aabc bc
2
ab a

Sample Output:
true
false

*/