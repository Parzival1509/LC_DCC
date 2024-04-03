// LC DCC 2024/03/16
// 525. Contiguous Array
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size(), sum = 0, subArray_length = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (sum == 0)
                subArray_length = i + 1;
            else if (mp.find(sum) != mp.end())
                subArray_length = max(subArray_length, i - mp[sum]);
            else mp[sum] = i;
        }

        return subArray_length;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.findMaxLength(nums) << endl;
    }

    return 0;
}

/* Sample Input
2
2
0 1
3
0 1 0

Sample Output
2
2

*/