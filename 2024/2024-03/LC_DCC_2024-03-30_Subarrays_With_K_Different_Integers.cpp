// LC DCC 2024/03/30
// 992. Subarrays with K Different Integers
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarray_with_atmost_k(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int left = 0, right = 0, ans = 0;

        while (right < nums.size()) {
            map[nums[right]]++;
            while (map.size() > k) {
                map[nums[left]]--;
                if (map[nums[left]] == 0)
                    map.erase(nums[left]);
                left++;
            }
            ans += right - left + 1;
            right++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int sub_with_max_element_k = subarray_with_atmost_k(nums, k);
        int reduced_sub_with_max_k = subarray_with_atmost_k(nums, k - 1);

        return (sub_with_max_element_k - reduced_sub_with_max_k);
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.subarraysWithKDistinct(nums, k) << endl;
    }

    return 0;
}

/* Sample Input
2
5 2
1 2 1 2 3
5 3
1 2 1 3 4

Sample Output
7
3

*/