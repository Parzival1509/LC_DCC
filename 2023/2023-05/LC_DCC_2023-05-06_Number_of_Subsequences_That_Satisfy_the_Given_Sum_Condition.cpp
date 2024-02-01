// LC DCC 2023/05/06
// 1498. Number of Subsequences That Satisfy the Given Sum Condition
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res = 0, mod = 1e9+7, l = 0, r = nums.size() - 1;
        vector<int> pre = {1};
        for(int i = 1; i <= nums.size(); ++i)
            pre.push_back((pre.back() << 1) % mod);   
                
        sort(begin(nums), end(nums));
        
        while(l <= r) {
            if (nums[l] + nums[r] > target) r--;
            else res = (res + pre[r - l++]) % mod;
        }

        return res;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, target;
        cin>>n>>target;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin>>i;
        cout<<ob.numSubseq(nums, target)<<endl;
    }
    return 0;
}

/* Sample Input:
3
4 9
3 5 6 7
4 10
3 3 6 8
6 12
2 3 3 4 6 7

Sample Output:
4
6
61

*/