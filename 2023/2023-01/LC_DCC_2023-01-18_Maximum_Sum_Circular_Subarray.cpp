// LC DCC 2023/01/18
// 918. Maximum Sum Circular Subarray
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, sum_mx = INT_MIN, sum_mn = INT_MAX, curr_mx = 0, curr_mn = 0;
        for(auto i: nums) {
            total += i;
            curr_mn += i;
            curr_mx += i;
            sum_mn = min(sum_mn, curr_mn);
            sum_mx = max(sum_mx, curr_mx);
            if(curr_mn > 0) curr_mn = 0;
            if(curr_mx < 0) curr_mx = 0;
        }
        return (total == sum_mn)? sum_mx: max(sum_mx, total-sum_mn);
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
        cout<<ob.maxSubarraySumCircular(nums)<<endl;
    }
    return 0;
}

/* Sample Input
3
4
1 -2 3 -2
3
5 -3 5
3
-3 -2 -3

Sample Output
3
10
-2

*/