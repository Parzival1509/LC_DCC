// LC DCC 2023/04/05
// 2439. Minimize Maximum of Array
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        ll ans = 0, cur = 0;
        for(int i=0; i<nums.size(); i++){
            cur += nums[i];
            ll val = ceil(cur / (i+1.0));
            ans = max(ans, val);
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
        cin>>n;
        vector<int> nums(n);
        for(int &i: nums)
            cin>>i;
        cout<<ob.minimizeArrayValue(nums)<<endl;
    }
    return 0;
}

/* Sample Input:
2
4
3 7 1 6
2
10 1

Sample Output:
5
10

*/