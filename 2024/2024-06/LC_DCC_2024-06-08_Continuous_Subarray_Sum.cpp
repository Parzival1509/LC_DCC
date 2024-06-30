// LC DCC 2024/06/08
// 523. Continuous Subarray Sum
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.find(sum % k) != mp.end()) {
                if (i - mp[sum % k] >= 2)
                    return true;
            } else mp[sum % k] = i;
        }
        
        return false;
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
        if(ob.checkSubarraySum(nums, k)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}

/* Sample Input
3
5 6
23 2 4 6 7
5 6
23 2 6 4 7
5 13
23 2 6 4 7

Sample Output
true
true
false

*/