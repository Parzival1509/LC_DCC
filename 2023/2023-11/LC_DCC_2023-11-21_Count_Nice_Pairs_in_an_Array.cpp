// LC DCC 2023/11/21
// 1814. Count Nice Pairs in an Array
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;

    int rev(int n) {
        int num = 0;
        while(n != 0) {
            num = num * 10 + n % 10;
            n /= 10;
        }

        return num;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
            nums[i] -= rev(nums[i]);

        sort(nums.begin(), nums.end());

        unordered_map<int, int> hsh;
        for(int i: nums)
            hsh[i]++;

        long ans = 0;
        for(auto& i: hsh)
            ans = (ans % mod + ((long)i.second * ((long)i.second - 1) / 2)) % mod;

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
        cout << ob.countNicePairs(nums) << endl;
    }

    return 0;
}

/* Sample Input:
2
4
42 11 1 97
5
13 10 35 24 76

Sample Output:
2
4

*/