// LC DCC 2023/10/29
// 458. Poor Pigs
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // // Approach 1: Using DP
        // vector<int> f(11, 1);
        // for(int i = 1; i <= 10; i++)
        //     f[i] = f[i - 1] * i;
        
        // minutesToTest = minutesToTest / minutesToDie;

        // if(buckets == 1) return 0;

        // vector<vector<int>> dp(11, vector<int> (minutesToTest + 1));
        // for(int i = 0; i < 11; i++)
        //     dp[i][0] = 1;
        // for(int i = 0; i <= minutesToTest; i++)
        //     dp[0][i] = 1;

        // for(int i = 1; i < 11; i++) {
        //     for(int j = 1; j <= minutesToTest; j++)
        //         for(int k = 0; k <= i; k++)
        //             dp[i][j] += f[i] / (f[i - k] * f[k]) * dp[i - k][j - 1];

        //     if(dp[i][minutesToTest] >= buckets)
        //         return i;
        // }
        
        // return 11;

        // Approach 2: Using Math
        return ceil(log2(buckets) / log2(int(minutesToTest / minutesToDie) + 1));
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int buckets, minutesToDie, minutesToTest;
        cin >> buckets >> minutesToDie >> minutesToTest;
        cout << ob.poorPigs(buckets, minutesToDie, minutesToTest) << endl;
    }

    return 0;
}

/* Sample Input:
2
4 15 15
4 15 30

Sample Output:
2
2

*/