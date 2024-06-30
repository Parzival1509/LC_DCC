// LC DCC 2024/06/16
// 330. Patching Array
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int result = 0, i = 0;

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                miss += miss;
                result++;
            }
        }

        return result;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<int> nums(m, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.minPatches(nums, n) << endl;
    }

    return 0;
}

/* Sample Input
3
2 6
1 3
3 20
1 5 10
3 5
1 2 2

Sample Output
1
2
0

*/