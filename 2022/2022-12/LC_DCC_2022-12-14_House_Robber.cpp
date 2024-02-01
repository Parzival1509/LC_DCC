// LC DCC 2022/12/14
// 198. House Robber
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()+1];
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2; i<=nums.size(); i++)
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
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
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        cout<<ob.rob(nums)<<endl;
    }
}

/* Sample Input
4
4
1 2 3 1
5
2 7 9 3 1
4
2 1 1 2
5
1 3 1 3 100

Sample Output
4
12
3
102

*/