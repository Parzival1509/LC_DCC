// LC DCC 2023/10/13
// 746. Min Cost Climbing Stairs
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 10000);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++)
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        dp[n] = min(dp[n - 1], dp[n - 2]);

        return dp[n];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> cost(n, 0);
        for(int &i: cost)
            cin >> i;
        cout << ob.minCostClimbingStairs(cost) << endl;
    }

    return 0;
}

/* Sample Input:
2
3
10 15 20
10
1 100 1 1 1 100 1 1 100 1

Sample Output:
15
6 

*/