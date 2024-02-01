// LC DCC 2023/11/17
// 1877. Minimize Maximum Pair Sum in Array
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n / 2; i++)
            ans = max(ans, nums[i] + nums[n - 1 - i]);

        return ans;
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
        cout << ob.minPairSum(nums) << endl;
    }

    return 0;
}

/* Sample Input:
2
4
3 5 2 3
6
3 5 4 2 4 6

Sample Output:
7
8

*/