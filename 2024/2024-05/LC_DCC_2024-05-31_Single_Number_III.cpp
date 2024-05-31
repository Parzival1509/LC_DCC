// LC DCC 2024/05/31
// 260. Single Number III
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int overall_xor = 0;
        for (int n : nums)
            overall_xor ^= n;

        int a = 0, b = 0, bit_pos_dif = 0;
        while (((overall_xor >> bit_pos_dif) & 1) != 1)
            bit_pos_dif++;

        for (int num : nums)
            if (((num >> bit_pos_dif) & 1) == 1)
                a ^= num;
            else b ^= num;

        return {a, b};
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        vector<int> ans = ob.singleNumber(nums);
        cout << ans[0] << ' ' << ans[1] << endl;
    }

    return 0;
}

/* Sample Input
3
2
0 1
2
-1 0
6
1 2 1 3 2 5

Sample Output
1 0
-1 0
3 5

*/