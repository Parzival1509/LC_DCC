// LC DCC 2023/10/21
// 1425. Constrained Subsequence Sum
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        // // Approach 1: Using Deque
        // deque<int> dq;
        // for(int i = 0; i < n; ++i) {
        //     nums[i] += !dq.empty()? nums[dq.front()]: 0;
            
        //     while(!dq.empty() && (i - dq.front() >= k || nums[i] >= nums[dq.back()])) {
        //         if(nums[i] >= nums[dq.back()])
        //             dq.pop_back();
        //         else dq.pop_front();
        //     }
            
        //     if(nums[i] > 0) dq.push_back(i);
        // }

        // return *max_element(nums.begin(), nums.end());

        // Approach 2: Using DP and Max Heap
        priority_queue<pair<int, int>>pq;
        pq.push({nums[0], 0});
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++) {
            while(!pq.empty()) {
                auto p = pq.top();
                if(i - p.second > k) pq.pop();
                else break;
            }
            
            dp[i] = max(nums[i], nums[i] + pq.top().first); 
            ans = max(ans, dp[i]);
            pq.push({dp[i], i});
        }

        return ans;
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
        cout << ob.constrainedSubsetSum(nums, k) << endl;
    }

    return 0;
}

/* Sample Input:
3
5 2
10 2 -10 5 20
3 1
-1 -2 -3
5 2
10 -2 -10 -5 20

Sample Output:
37
-1
23

*/