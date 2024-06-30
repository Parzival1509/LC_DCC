// LC DCC 2024/06/24
// 995. Minimum Number of K Consecutive Bit Flips
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), flipped = 0, res = 0;
        vector<int> isFlipped(n, 0);

        for (int i = 0; i < n; ++i) {
            if (i >= k)
                flipped ^= isFlipped[i - k];
            if (flipped == nums[i]) {
                if (i + k > n)
                    return -1;

                isFlipped[i] = 1;
                flipped ^= 1;
                res++;
            }
        }

        return res;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.minKBitFlips(nums, k) << endl;
    }

    return 0;
}

/* Sample Input
3
3 1
0 1 0
3 2
1 1 0
8 3
0 0 0 1 0 1 1 0

Sample Output
2
-1
3

*/