// LC DCC 2024/02/15
// 2971. Find Polygon With the Largest Perimeter
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = 0;
        
        // // Approach 1: Using Backward Iteration
        // // T.C. = O(N * logN), S.C. = O(1)
        // for(auto i : nums)
        //     sum += i;
        
        // for(int i = n - 1; i >= 2; i--) {
        //     sum -= nums[i];
        //     if(sum > nums[i])
        //         return sum + nums[i];
        // }

        // return -1;

        // Approach 2: Using Forward Iteration
        // T.C. = O(N * logN), S.C. = O(1)
        long long ans = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] < sum)
                ans = nums[i] + sum;
            sum += nums[i];
        }
        
        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.largestPerimeter(nums) << endl;
    }

    return 0;
}

/* Sample Input
3
3
5 5 5
3
5 5 50
7
1 12 1 2 5 50 3

Sample Output
15
-1
12

*/