// LC DCC 2023/06/23
// 1027. Longest Arithmetic Subsequence
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<vector<int>> dp(n, vector<int> (2001, 1));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++) {
                int diff = 1000 + (nums[i] - nums[j]);
                dp[i][diff] = 1 + dp[j][diff];
                ans = max(ans, dp[i][diff]);
            }
        
        return ans;
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
        cout << ob.longestArithSeqLength(nums) << endl;
    }
    return 0;
}

/* Sample Input:
3
4
3 6 9 12
5
9 4 7 2 10
7
20 1 15 3 10 5 8

Sample Output:
4
3
4

*/