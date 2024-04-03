// LC DCC 2024/03/27
// 713. Subarray Product Less Than K
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = 0, product = 1, count = 0;
        if (k <= 1)
            return 0;
        
        while (right < n) {
            product *= nums[right];
            while (product >= k)
                product /= nums[left++];
            count += 1 + (right - left);
            right++;
        }

        return count;
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
        cout << ob.numSubarrayProductLessThanK(nums, k) << endl;
    }

    return 0;
}

/* Sample Input
2
4 100
10 5 2 6
3 0
1 2 3

Sample Output
8
0

*/