// LC DCC 2023/10/03
// 1512. Number of Good Pairs
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> ct(101, 0);
        for(int i = 0; i < nums.size(); i++)
            ct[nums[i]]++;

        int ans = 0;
        for(int i = 0; i < 100; i++)
            ans += ct[i] * (ct[i] - 1) / 2;

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
        cout << ob.numIdenticalPairs(nums) << endl;
    }

    return 0;
}

/* Sample Input:
3
6
1 2 3 1 1 3
4
1 1 1 1
3
1 2 3

Sample Output:
4
6
0

*/