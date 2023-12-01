// LC DCC 2023/11/18
// 1838. Frequency of the Most Frequent Element
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool isPossible(vector<int> &nums, vector<long> &diff, vector<long> &prefixSum, int k, int freq) {
        int n = nums.size();
        long times = 0;
        for(int i = freq - 2; i >= 0; i--)
            times += nums[freq - 1] - nums[i];

        long minTimes = times;
        for(int i = freq; i < n; i++) {
            times = times - (prefixSum[i - 1] - prefixSum[i - freq]) + diff[i] * (freq - 1);
            minTimes = min(minTimes, times);
        }

        return minTimes <= (long)k;
    }

    void countingSort(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());

        vector<int> countMap(maxElement + 1, 0);
        for(int num: nums)
            countMap[num]++;

        int index = 0;
        for(int i = 0; i <= maxElement; i++)
            while(countMap[i]-- > 0)
                nums[index++] = i;
    }

    int maxFrequency(vector<int>& nums, int k) {
        // // Approach 1: Binary Search
        // // T.C. = O(N * log(N)), S.C. = O(N)

        // int n = nums.size();
        // sort(nums.begin(), nums.end());

        // // Calculating the difference between adjacent elements
        // vector<long> diff(n, 0);
        // for(int i = 1; i < n; i++)
        //     diff[i] = nums[i] - nums[i - 1];

        // // Calculating the prefix sum of the differences
        // vector<long> prefixSum(n, nums[0]);
        // for(int i = 1; i < n; i++)
        //     prefixSum[i] = prefixSum[i - 1] + diff[i];

        // int lo = 1, hi = n;
        // while(lo < hi) {
        //     int mid = lo + (hi - lo + 1) / 2;
        //     if(isPossible(nums, diff, prefixSum, k, mid))
        //         lo = mid;
        //     else hi = mid - 1;
        // }

        // return lo;

        // // Approach 2: Two Pointers / Sliding Window
        // // T.C. = O(N * log(N)), S.C. = O(1)

        // int maxFrequency = 0;
        // long currentSum = 0; // Initialize the current sum of the subarray elements

        // sort(nums.begin(), nums.end());

        // for(int left = 0, right = 0; right < nums.size(); ++right) {
        //     currentSum += nums[right]; // Include the current element in the subarray sum

        //     // Check if the current subarray violates the condition (sum + k < nums[right] * length)
        //     while(currentSum + k < (long)(nums[right]) * (right - left + 1)) {
        //         currentSum -= nums[left];
        //         left++;
        //     }

        //     // Update the maximum frequency based on the current subarray length
        //     maxFrequency = max(maxFrequency, right - left + 1);
        // }

        // return maxFrequency;

        // Approach 3: Sliding Window & Greedy
        // T.C. = O(N + K), S.C. = O(K)

        countingSort(nums);
        int start = 0, maxFrequency = 1;
        long long subarraySum = 0;

        for(int i = 0; i < nums.size(); i++) {
            int subarrayLength = i - start + 1;
            long long subarrayProduct = (long long)nums[i] * subarrayLength;
            subarraySum += nums[i];

            // Adjust the subarray to satisfy the condition (product - sum <= k)
            while(subarrayProduct - subarraySum > k) {
                subarraySum -= nums[start];
                start++;
                subarrayLength--;
                subarrayProduct = (long long)nums[i] * subarrayLength;
            }

            maxFrequency = max(maxFrequency, subarrayLength);
        }

        return maxFrequency;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.maxFrequency(nums, k) << endl;
    }

    return 0;
}

/* Sample Input:
3
3 5
1 2 4
4 5
1 4 8 13
3 2
3 9 6

Sample Output:
3
2
1

*/