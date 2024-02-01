// LC DCC 2023/09/01
// 338. Counting Bits
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for(int i = 0; i <= n; i++)
            ans[i] = __builtin_popcount(i);
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ans = ob.countBits(n);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
2
5

Sample Output:
0 1 1 
0 1 1 2 1 2 

*/