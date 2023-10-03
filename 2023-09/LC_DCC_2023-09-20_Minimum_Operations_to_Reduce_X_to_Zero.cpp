// LC DCC 2023/09/20
// 1658. Minimum Operations to Reduce X to Zero
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {        
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if(target < 0) return -1;

        int L = 0, R = 0, maxn = -1;
        while(R < n) {
            target -= nums[R++];

            while(target < 0) target += nums[L++];
            if(target == 0) maxn = max(maxn, R - L);
        }

        return (maxn == -1)? maxn: n - maxn;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.minOperations(nums, x) << endl;
    }

    return 0;
}

/* Sample Input:
3
5 5
1 1 4 2 3
5 4
5 6 7 8 9
6 10
3 2 20 1 1 3

Sample Output:
2
-1
5

*/