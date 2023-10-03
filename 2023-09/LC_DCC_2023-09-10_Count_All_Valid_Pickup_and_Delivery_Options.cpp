// LC DCC 2023/09/10
// 1359. Count All Valid Pickup and Delivery Options
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int MOD = 1e9 + 7;

    long long calculateOrdersCount(long long remainingPairs, vector<long long> &dp) {
        if(remainingPairs == 0)
            return 1;

        if(dp[remainingPairs] != -1)
            return dp[remainingPairs];

        long long currentResult = calculateOrdersCount(remainingPairs - 1, dp) * (2 * remainingPairs - 1) * remainingPairs % MOD;

        return dp[remainingPairs] = currentResult;
    }

    int countOrders(int numPairs) {
        // // Approach 1: Memoization
        // vector<long long> dp (numPairs + 1, -1);
        // return calculateOrdersCount(numPairs, dp);

        // Approach 2: Tabulation
        long long count = 1;
        for(int i = 2; i <= numPairs; ++i)
            count = (count * (2 * i - 1) * i) % MOD;
        
        return (int)count;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.countOrders(n) << endl;
    }

    return 0;
}

/* Sample Input:
3
1 2 3

Sample Output:
1
6
90

*/