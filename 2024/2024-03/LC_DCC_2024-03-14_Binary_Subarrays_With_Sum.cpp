// LC DCC 2024/03/14
// 930. Binary Subarrays With Sum
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0, total_subarrays = 0;

        for (int num : nums) {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end())
                total_subarrays += count[curr_sum - goal];
            count[curr_sum]++;
        }

        return total_subarrays;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, goal;
        cin >> n >> goal;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.numSubarraysWithSum(nums, goal) << endl;
    }

    return 0;
}

/* Sample Input
2
5 2
1 0 1 0 1
5 0
0 0 0 0 0

Sample Output
4
15

*/