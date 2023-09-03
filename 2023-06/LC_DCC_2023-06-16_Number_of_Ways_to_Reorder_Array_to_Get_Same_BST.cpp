// LC DCC 2023/06/16
// 1569. Number of Ways to Reorder Array to Get Same BST
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// // Approach 1: DP
// class Solution {
//     vector<vector<long long>> dp;
//     long long MOD = 1e9 + 7;

//     long long solve(vector<int> &nums) {
//         if (nums.size() <= 1) return 1;

//         vector<int> l, r;
//         for (int i = 1; i < nums.size(); ++i) {
//             if (nums[i] > nums[0]) r.push_back(nums[i]);
//             else l.push_back(nums[i]);
//         }
//         int n = l.size(), m = r.size();
//         return solve(l) * solve(r) % MOD * dp[n + m][n] % MOD;
//     }

// public:
//     int numOfWays(vector<int> &nums) {
//         dp = vector<vector<long long>> (nums.size() + 1, vector<long long> (nums.size() + 1, 0));
//         for (int i = 1; i < nums.size() + 1; ++i) {
//             dp[i][0] = 1;
//             dp[i][1] = i;
//             dp[i][i - 1] = i;
//             dp[i][i] = 1;
//         }

//         for (int i = 2; i < nums.size() + 1; ++i) {
//             for (int j = 2; j < nums.size() + 1; ++j) {
//                 if (i >= j) dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;
//                 else break;
//             }
//         }

//         return solve(nums) - 1;
//     }
// };

// Approach 2: Pascal Triangle
class Solution {
public:
    vector<vector<long long>> pascal;
    int MOD = 1e9 + 7;
    
    int numOfWays(vector<int>& nums) {
        int N = nums.size();
        pascal = vector<vector<long long>> (N + 1);
        for(int i = 0; i < N + 1; i ++) {
            pascal[i] = vector<long long> (i + 1, 1);
            for(int j = 1; j < i; j ++)
                pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % MOD;
        }

        return dfs(nums) - 1;
    }
    
    int dfs(vector<int> nums) {
        if(nums.size() <= 2) return 1;

        vector<int> left, right;
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] < nums[0])
                left.push_back(nums[i]);
            else right.push_back(nums[i]);
        
        return (((dfs(left) * pascal[nums.size() - 1][left.size()]) % MOD) * dfs(right)) % MOD;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.numOfWays(nums) << endl;
    }
    return 0;
}

/* Sample Input:
3
3
2 1 3
5
3 4 5 1 2
3
1 2 3

Sample Output:
1
5
0

*/