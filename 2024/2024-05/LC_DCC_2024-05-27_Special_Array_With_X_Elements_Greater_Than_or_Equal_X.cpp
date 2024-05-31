// LC DCC 2024/05/27
// 1608. Special Array With X Elements Greater Than or Equal X
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();

        if (nums[n - 1] > n)
            return n;
        if (nums[0] == 0)
            return -1;

        int l = 0, r = n - 1, m = 0;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] > m)
                l = m + 1;
            else if (nums[m] < m)
                r = m - 1;
            else return -1;
        }

        return nums[m] > m ? m + 1 : m;
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
        cout << ob.specialArray(nums) << endl;
    }

    return 0;
}

/* Sample Input
3
2
3 5
2
0 0
5
0 4 3 0 4

Sample Output
2
-1
3

*/