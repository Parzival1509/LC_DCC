// LC DCC 2023/10/28
// 1220. Count Vowels Permutation
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int countVowelPermutation(int n) {
        int MOD = 1e9 + 7;
        ll a = 1, e = 1, i = 1, o = 1, u = 1;
        
        for(int j = 1; j < n; j++) {
            ll a_next = e;
            ll e_next = (a + i) % MOD;
            ll i_next = (a + e + o + u) % MOD;
            ll o_next = (i + u) % MOD;
            ll u_next = a;
            
            a = a_next, e = e_next, i = i_next, o = o_next, u = u_next;
        }
        
        return (a + e + i + o + u) % MOD;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.countVowelPermutation(n) << endl;
    }

    return 0;
}

/* Sample Input:
4
1 2 3 5

Sample Output:
5
10
19
68

*/