// LC DCC 2023/08/30
// 2366. Minimum Replacements to Sort the Array
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size(), curr_min = nums[n - 1];
        long long ans = 0;

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] > curr_min) {
                int parts = ceil(nums[i] / double(curr_min));
                int steps = parts - 1;
                ans = ans + steps;
                curr_min = min(curr_min, nums[i] / parts);
            }
            else curr_min = nums[i];
        }

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
        cout << ob.minimumReplacement(nums) << endl;
    }

    return 0;
}

/* Sample Input:
2
3
3 9 3
5
1 2 3 4 5

Sample Output:
2
0

*/