// LC DCC 2023/09/09
// 377. Combination Sum IV
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int target) {
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(dp[target] != -1) return dp[target];

        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
            ans += solve(nums, dp, target - nums[i]);

        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        // // Approach 1: Memoization
        // vector<int> dp(target + 1, -1);
        // return solve(nums, dp, target);

        // Approach 2: Tabulation
        vector<unsigned> dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target; i++)
            for(int x: nums)
                if(i >= x)
                    dp[i] += dp[i - x];

        return dp[target];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, target;
        cin >> n >> target;

        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.combinationSum4(nums, target) << endl;
    }

    return 0;
}

/* Sample Input:
2
3 4
1 2 3
1 3
9

Sample Output:
7
0

*/