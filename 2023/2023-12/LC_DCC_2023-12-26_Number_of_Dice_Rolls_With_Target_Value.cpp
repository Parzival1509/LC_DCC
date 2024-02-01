// LC DCC 2023/12/26
// 1155. Number of Dice Rolls With Target Sum
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll solve(int n, int k, int target) {
        vector<ll> prev(target + 1, 0), curr(target + 1, 0);
        prev[0] = 1;
        int mod = 1e9 + 7;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                ll ans = 0;
                for(int x = 1; x <= k; x++)
                    if(j - x >= 0)
                        ans += prev[j- x ] % mod;
                
                curr[j] = ans;
            }
            prev = curr;
        }

        return prev[target] % mod;
    }

    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, k, target;
        cin >> n >> k >> target;
        cout << ob.numRollsToTarget(n, k, target) << endl;
    }

    return 0;
}

/* Sample Input:
3
1 6 3
2 6 7
30 30 500

Sample Output:
1
6
222616187

*/