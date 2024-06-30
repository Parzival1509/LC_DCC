// LC DCC 2024/06/14
// 945. Minimum Increment to Make Array Unique
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int numTracker = 0, minIncrement = 0;
        for (int num : nums) {
            numTracker = max(numTracker, num);
            minIncrement += numTracker - num;
            numTracker += 1;
        }

        return minIncrement;
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
        cout << ob.minIncrementForUnique(nums) << endl;
    }

    return 0;
}

/* Sample Input
2
3
1 2 2
6
3 2 1 2 1 7

Sample Output
1
6

*/