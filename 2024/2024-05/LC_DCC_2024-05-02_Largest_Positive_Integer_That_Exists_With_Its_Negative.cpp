// LC DCC 2024/05/02
// 2441. Largest Positive Integer That Exists With Its Negative
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums[nums.size() - 1] < 0)
            return -1;
        
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == 0)
                return nums[j];
            else if ((nums[i] + nums[j]) < 0)
                i++;
            else j--;

            if (nums[i] > 0 || nums[j] < 0)
                break;
        }

        return -1;
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
        cout << ob.findMaxK(nums) << endl;
    }

    return 0;
}

/* Sample Input
3
4
-1 2 -3 3
6
-1 10 6 7 -7 1
6
-10 8 6 7 -2 -3

Sample Output
3
7
-1

*/