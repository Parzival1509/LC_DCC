// LC DCC 2023/05/14
// 1799. Maximize Score After N Operations
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int func(vector<int>& nums, int op, int mask, vector<int>& dp, vector<vector<int>>& gcd) {
        int m = nums.size(), n = nums.size()/2;
        
        if(op > n) return 0;
        if(dp[mask] != -1) return dp[mask];

        for(int i=0; i<m; i++) {
            if(mask & (1<<i)) continue;

            for(int j=i+1; j<m; j++) {
                if(mask & (1<<j)) continue;

                int newMask = (1<<i) | (1<<j) | mask;
                int score = op * gcd[i][j] + func(nums, op+1, newMask, dp, gcd);
                dp[mask] = max(dp[mask], score);
            }
        }
        return dp[mask];
    }

    int maxScore(vector<int>& nums) {
        vector<int> dp(1<<14, -1);
        int m = nums.size(), n = nums.size()/2;
        vector<vector<int>> gcd(m, vector<int> (m, 0));
        for(int i=0; i<m; i++)
            for(int j=0; j<m; j++)
                gcd[i][j] = __gcd(nums[i], nums[j]);

        return func(nums, 1, 0, dp, gcd);
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin>>i;
        cout<<ob.maxScore(nums)<<endl;
    }
    return 0;
}

/* Sample Input:
3
2
1 2
4
3 4 6 8
6
1 2 3 4 5 6

Sample Output:
1
11
14

*/