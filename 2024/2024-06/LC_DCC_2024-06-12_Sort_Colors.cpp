// LC DCC 2024/06/12
// 75. Sort Colors
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, n = nums.size();
        for(int num : nums)
            if(num == 0) zeros++;
            else if(num == 1) ones++;

        for(int i = 0; i < zeros; ++i)
            nums[i] = 0;

        for(int i = zeros; i < zeros + ones; ++i)
            nums[i] = 1;

        for(int i = zeros + ones; i < n; ++i)
            nums[i] = 2;
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
        ob.sortColors(nums);
        for(int i: nums)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
6
2 0 2 1 1 0
3
2 0 1

Sample Output
0 0 1 1 2 2 
0 1 2 

*/