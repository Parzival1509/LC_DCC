// LC DCC 2024/06/23
// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> increase, decrease;
        int max_len = 0, left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (!increase.empty() && nums[right] < increase.back())
                increase.pop_back();
            increase.push_back(nums[right]);

            while (!decrease.empty() && nums[right] > decrease.back())
                decrease.pop_back();
            decrease.push_back(nums[right]);

            while (decrease.front() - increase.front() > limit) {
                if (nums[left] == decrease.front())
                    decrease.pop_front();
                if (nums[left] == increase.front())
                    increase.pop_front();
                ++left;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, limit;
        cin >> n >> limit;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.longestSubarray(nums, limit) << endl;
    }

    return 0;
}

/* Sample Input
3
4 4
8 2 4 7
6 5
10 1 2 4 7 2
4 0
4 2 2 2 4 4 2 2

Sample Output
2
4
3

*/