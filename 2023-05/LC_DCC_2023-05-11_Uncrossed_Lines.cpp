// LC DCC 2023/05/11
// 1035. Uncrossed Lines
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m < n) {
            swap(nums1, nums2);
            swap(m, n);
        }
        vector<int> dp(n + 1);
        for(int i = 1; i <= m; i++) {
            int prev = 0;
            for(int j = 1; j <= n; j++) {
                int curr = dp[j];
                if(nums1[i-1] == nums2[j-1]) dp[j] = prev + 1;
                else dp[j] = max(dp[j-1], curr);
                prev = curr;
            }
        }
        return dp[n];
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int m, n;
        cin>>m>>n;
        vector<int> nums1(m, 0), nums2(n, 0);
        for(int &i: nums1)
            cin>>i;
        for(int &i: nums2)
            cin>>i;
        cout<<ob.maxUncrossedLines(nums1, nums2)<<endl;
    }
    return 0;
}

/* Sample Input:
3
3 3
1 4 2
1 2 4
5 6
2 5 1 2 5
10 5 2 1 5 2
5 6
1 3 7 1 7 5
1 9 2 5 1

Sample Output:
2
3
2

*/