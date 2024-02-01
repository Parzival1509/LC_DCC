// LC DCC 2023/11/09
// 1759. Count Number of Homogenous Substrings
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;

    int countHomogenous(string s) {
        long long ans = 0, ct = 1;

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) ct++;
            else {
                if(ct == 1) ans++;
                else {
                    ans = (ans + (ct * (ct + 1) / 2) % mod) % mod;
                    ct = 1;
                }
            }
        }

        if(ct == 1) ans++;
        else ans = (ans + (ct * (ct + 1) / 2) % mod) % mod;

        return (int) ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.countHomogenous(s) << endl;
    }

    return 0;
}

/* Sample Input:
3
xy
aaaaa
abbcccaa

Sample Output:
2
15
13

*/