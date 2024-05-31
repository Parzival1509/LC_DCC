// LC DCC 2024/05/23
// 2597. The Number of Beautiful Subsets
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& nums, int idx, int k, unordered_map<int, int>& mp) {
        if (idx == nums.size())
            return 1;

        int taken = 0;
        if (!mp[nums[idx] - k] && !mp[nums[idx] + k]) {
            mp[nums[idx]]++;
            taken = dfs(nums, idx + 1, k, mp);
            mp[nums[idx]]--;
        }
        int notTaken = dfs(nums, idx + 1, k, mp);

        return taken + notTaken;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = dfs(nums, 0, k, mp);
        return ans - 1;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.beautifulSubsets(nums, k) << endl;
    }

    return 0;
}

/* Sample Input
2
1 1
1
3 2
2 4 6

Sample Output
1
4

*/