// LC DCC 2024/03/29
// 2962. Count Subarrays Where Max Element Appears at Least K Times
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long max_num = *max_element(nums.begin(), nums.end()), ct = 0;
        long long left = 0, right = 0, ans = 0;

        while (right < nums.size()) {
            if (nums[right] == max_num)
                ct++;

            while (ct >= k) {
                if (nums[left] == max_num)
                    ct--;
                left++;
                ans += nums.size() - right;
            }
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
        cout << ob.countSubarrays(nums, k) << endl;
    }

    return 0;
}

/* Sample Input
2
5 2
1 3 2 3 3
4 3
1 4 2 1

Sample Output
6
0

*/