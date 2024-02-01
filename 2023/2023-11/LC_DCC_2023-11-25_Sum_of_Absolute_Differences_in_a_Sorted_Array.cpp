// LC DCC 2023/11/25
// 1685. Sum of Absolute Differences in a Sorted Array
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> prefixSum(n), suffixSum(n);
        
        // Calculate and initialize the prefix sums & suffixSum array
        prefixSum[0] = nums[0];
        suffixSum[n - 1] = nums[n - 1];
        
        // Calculate the prefix sums & suffixSum array in one loop
        for(int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
            suffixSum[n - i - 1] = suffixSum[n - i] + nums[n - i - 1];
        }
        
        // Calculate absolute differences and update the result array
        for(int i = 0; i < n; ++i) {
            int currentAbsoluteDiff = ((nums[i] * i) - prefixSum[i]) + (suffixSum[i] - (nums[i] * (n - i - 1)));
            result[i] = currentAbsoluteDiff;
        }
        
        return result;
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
        vector<int> ans = ob.getSumAbsoluteDifferences(nums);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
3
2 3 5
5
1 4 6 8 10

Sample Output:
4 3 5 
24 15 13 15 21 

*/