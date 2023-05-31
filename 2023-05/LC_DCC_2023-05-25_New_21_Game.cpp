// LC DCC 2023/05/25
// 837. New 21 Game
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1);
        double currSum = 1.0, ans = 0.0;
        dp[0] = 1.0;

        for(int i = 1; i < n+1; i++) {
            dp[i] = currSum / maxPts;
            if(i < k) currSum += dp[i];
            else ans += dp[i];
            
            if(i - maxPts >= 0)
                currSum -= dp[i - maxPts];
        }

        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, k, maxPts;
        cin>>n>>k>>maxPts;
        cout<<fixed<<setprecision(5)<<ob.new21Game(n, k, maxPts)<<endl;
    }
    return 0;
}

/* Sample Input:
3
10 1 10
6 1 10
21 17 10

Sample Output:
1.00000
0.60000
0.73278

*/