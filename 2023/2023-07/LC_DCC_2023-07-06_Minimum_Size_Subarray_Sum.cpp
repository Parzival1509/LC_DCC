// LC DCC 2023/07/06
// 209. Minimum Size Subarray Sum
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // Sliding Window Approach
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, mn = INT_MAX;
        while(j < nums.size()) {
            sum += nums[j];
            while(sum >= target) {
                sum -= nums[i];
                mn = min(j - i + 1, mn);
                i++;
            }
            j++;
        }

        if(mn == INT_MAX) return 0;
        return mn;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n, target;
        cin >> n >> target;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.minSubArrayLen(target, nums) << endl;
    }
    return 0;
}

/* Sample Input:
3
6 7
2 3 1 2 4 3
3 4
1 4 4
8 11
1 1 1 1 1 1 1 1

Sample Output:
2
1
0

*/