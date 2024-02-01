// LC DCC 2023/10/08
// 1458. Max Dot Product of Two Subsequences
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // int solve(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp, int i, int j) {
    //     if(i == nums1.size() || j == nums2.size())
    //         return INT_MIN;

    //     if(dp[i][j] != INT_MIN) return dp[i][j];

    //     dp[i][j] = max(nums1[i] * nums2[j] + max(solve(nums1, nums2, dp, i + 1, j + 1), 0), max(solve(nums1, nums2, dp, i + 1, j), solve(nums1, nums2, dp, i, j + 1)));

    //     return dp[i][j];
    // }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        // // Approach 1: Memoization, S.C. = O(n * m)
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, INT_MIN));
        // return solve(nums1, nums2, dp, 0, 0);

        // // Approach 2: Tabulation, S.C. = O(n * m);
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, INT_MIN));
        // for(int i = 1; i <= n; i++)
        //     for(int j = 1; j <= m; j++)
        //         dp[i][j] = max(nums1[i - 1] * nums2[j - 1] + max(dp[i - 1][j - 1], 0), max(dp[i - 1][j], dp[i][j - 1]));

        // return dp[n][m];

        // Approach 3: Space-Optimised Tabulation, S.C. = O(m)
        vector<int> curr(m + 1, INT_MIN), prev(m + 1, INT_MIN);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int cp = nums1[i - 1] * nums2[j - 1];
                curr[j] = max({cp, prev[j], curr[j - 1], cp + max(0, prev[j - 1])});
            }
            swap(curr, prev);
        }

        return prev[m];
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums1(n, 0), nums2(m, 0);
        for(int &i: nums1)
            cin >> i;
        for(int &i: nums2)
            cin >> i;
        cout << ob.maxDotProduct(nums1, nums2) << endl;
    }

    return 0;
}

/* Sample Input:
3

2 2
-1 -1
1 1

2 3
3 -2
2 -6 7

4 3
2 1 -2 5
3 0 -6


Sample Output:
-1
21
18

*/