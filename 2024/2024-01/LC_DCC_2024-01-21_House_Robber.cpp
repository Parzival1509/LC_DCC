// LC DCC 2024/01/21
// 198. House Robber
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size() + 1];
        dp[0] = 0, dp[1] = nums[0];
        for(int i = 2; i <= nums.size(); i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        
        return dp[nums.size()];
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.rob(nums) << endl;
    }

    return 0;
}

/* Sample Input
4
4
1 2 3 1
2
2 1
4
2 1 1 2
5
2 7 9 3 1

Sample Output
4
2
4
12

*/