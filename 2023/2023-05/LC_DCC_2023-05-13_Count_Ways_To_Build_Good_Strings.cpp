// LC DCC 2023/05/13
// 2466. Count Ways To Build Good Strings
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> dp;
    const int mod = 1e9+7;
    int solve(int low, int high, int zero, int one, int str) {
        if(str > high) return 0;
        if(dp[str] != -1) return dp[str];
        
        return dp[str] = ((str >= low) + solve(low, high, zero, one, str + zero) % mod + solve(low, high, zero, one, str + one) % mod) % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(100002, -1);
        return solve(low, high, zero, one, 0);
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int low, high, zero, one;
        cin>>low>>high>>zero>>one;
        cout<<ob.countGoodStrings(low, high, zero, one)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3 3 1 1
2 3 1 2

Sample Output:
8
5

*/