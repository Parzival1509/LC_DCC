// LC DCC 2023/01/19
// 974. Subarray Sums Divisible by K
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mp;
        int sum = 0, ans = 0;
        mp[0] = 1;
        for(int n: nums) {
            sum = ((sum + n)%k + k)%k;
            mp[sum]++;
            if(mp[sum] > 1) ans += mp[sum] - 1;
        }
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n, k;
        cin>>n>>k;
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        cout<<ob.subarraysDivByK(nums, k)<<endl;
    }
    return 0;
}

/* Sample Input
2
6 5
4 5 0 -2 -3 1
1 9
5

Sample Output
7
0

*/