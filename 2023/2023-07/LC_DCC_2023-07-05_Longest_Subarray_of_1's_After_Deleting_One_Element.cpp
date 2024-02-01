// LC DCC 2023/07/05
// 1493. Longest Subarray of 1's After Deleting One Element
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), left = 0, zeroes = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeroes++;
            while (zeroes > 1) {
                if (nums[left] == 0) zeroes--;
                left++;
            }
            ans = max(ans, right - left + 1 - zeroes);
        }

        return (ans == n)? ans - 1: ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.longestSubarray(nums) << endl;
    }
    return 0;
}

/* Sample Input:
3
3
1 1 1
4
1 1 0 1
9
0 1 1 1 0 1 1 0 1

Sample Output:
2
3
5

*/