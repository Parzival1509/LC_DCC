// LC DCC 2023/06/20
// 2090. K Radius Subarray Averages
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        vector<long> pre(n + 1, 0);
        for(int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + nums[i - 1];

        for(int i = 0 + k; i < n - k; i++)
            ans[i] = (pre[i + 1 + k] - pre[i - k]) / (2 * k + 1);

        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        vector<int> ans = ob.getAverages(nums, k);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

/* Sample Input:
3
9 3
7 4 3 9 1 8 5 2 6
1 0
100
1 100
8

Sample Output:
-1 -1 -1 5 4 4 -1 -1 -1 
100 
-1 

*/