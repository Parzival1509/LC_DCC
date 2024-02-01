// LC DCC 2022/12/24
// 790. Domino and Tromino Tiling
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTilings(int n) {
        int dp[1001], m=1e9+7;
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        for(int i=3; i<=n; i++)
            dp[i] = (2*dp[i-1]%m + dp[i-3]%m)%m;
        return dp[n];
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        cout<<ob.numTilings(n)<<endl;
    }
}

/* Sample Input
10
1 2 3 4 5 6 7 30 35 100

Sample Output
1
2
5
11
24
53
117
312342182
29460134
190242381

*/