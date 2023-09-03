// LC DCC 2023/06/21
// 2448. Minimum Cost to Make Array Equal
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long findCost(vector<int>& nums, vector<int>& cost, int all) {
        long totalCost = 0L;
        for (int i = 0; i < nums.size(); i++)
            totalCost += 1L * abs(nums[i] - all) * cost[i];
        return totalCost;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        
        long ans = 0;
        while (left < right) {
            int mid = (left + right) / 2;
            long cost1 = findCost(nums, cost, mid);
            long cost2 = findCost(nums, cost, mid + 1);
            if (cost1 > cost2) {
                left = mid + 1;
                ans = cost2;
            }
            else {
                right = mid;
                ans = cost1;
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0), cost(n, 0);
        for(int &i: nums)
            cin >> i;
        for(int &i: cost)
            cin >> i;
        cout << ob.minCost(nums, cost) << endl;
    }
    return 0;
}

/* Sample Input:
2
4
1 3 5 2
2 3 1 14
5
2 2 2 2 2
4 2 8 1 3

Sample Output:
8
0

*/