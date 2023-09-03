// LC DCC 2023/08/13
// 2369. Check if There is a Valid Partition For The Array
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // Approach 1: Memoization
    bool solve(vector<int> &nums, vector<int> &dp, int i) {
        if(i == -1) return 1;
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];

        bool two = false, three = false, inc = false;

        if(nums[i] == nums[i - 1])
            two = solve(nums, dp, i - 2);
        if(i > 1 && (nums[i] == nums[i - 1]) && (nums[i] == nums[i - 2]))
            three = solve(nums, dp, i - 3);
        if(i > 1 && (nums[i] == nums[i - 1] + 1) && (nums[i] == nums[i - 2] + 2))
            inc = solve(nums, dp, i - 3);
        
        return dp[i] = two || three || inc;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, -1);
        // return solve(nums, dp, n - 1);

        // Approach 2: Tabulation
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for(int i = 1; i < n; i++) {
            bool two = false, three = false, inc = false;

            if(nums[i] == nums[i - 1])
                two = dp[i - 1];
            if(i > 1 && (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]))
                three = dp[i - 2];
            if(i > 1 && (nums[i] == nums[i - 1] + 1) && (nums[i] == nums[i - 2] + 2))
                inc = dp[i - 2];
            
            dp[i + 1] = two || three || inc;
        }

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
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        if(ob.validPartition(nums)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }

    return 0;
}

/* Sample Input:
4
5
4 4 4 5 6
4
1 1 1 2
6
1 1 1 1 2 3
3
1 3 3

Sample Output:
true 
false 
true 
false 

*/