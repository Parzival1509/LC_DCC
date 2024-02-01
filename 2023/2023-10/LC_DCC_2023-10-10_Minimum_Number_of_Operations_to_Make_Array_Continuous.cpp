// LC DCC 2023/10/10
// 2009. Minimum Number of Operations to Make Array Continuous
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), left = 0;
        int maxCount = 1; // Initialize the maximum count of distinct elements
        int currentCount = 1; // Initialize the count of distinct elements in the current window

        for(int right = 1; right < n; ++right) {
            if(nums[right] == nums[right - 1])
                continue; // Skip duplicates

            // Check if the current window size is less than or equal to the difference between the maximum and minimum values
            while(nums[right] - nums[left] > n - 1) {
                if(left < n && nums[left + 1] == nums[left])
                    currentCount++;
                // Move the left pointer to shrink the window
                left++;
                currentCount--;
            }

            currentCount++;
            maxCount = max(maxCount, currentCount);
        }

        return n - maxCount;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.minOperations(nums) << endl;
    }

    return 0;
}

/* Sample Input:
5
4
4 2 5 3
5
1 2 3 5 6
4
1 10 100 1000
6
8 5 9 9 8 4
10
41 33 29 33 35 26 47 24 18 28

Sample Output:
0
1
3
2
5

*/