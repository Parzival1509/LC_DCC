// LC DCC 2024/03/28
// 2958. Length of Longest Subarray With at Most K Frequency
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0, right = 0, ans = 0, n = nums.size();
        unordered_map<int, int> map;

        while (left < n && right < n) {
            map[nums[right]]++;
            while (map[nums[right]] > k) {
                map[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        
        return ans;
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
        cout << ob.maxSubarrayLength(nums, k) << endl;
    }

    return 0;
}

/* Sample Input
3
8 2
1 2 3 1 2 3 1 2
8 1
1 2 1 2 1 2 1 2
7 4
5 5 5 5 5 5 5

Sample Output
6
2
4

*/