// LC DCC 2024/01/22
// 645. Set Mismatch
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), xorAll = 0, xorArray = 0;
        for (int i = 1; i <= n; i++)
            xorAll ^= i;
        for (int num : nums)
            xorArray ^= num;
       
        int xorResult = xorArray ^ xorAll;
        int rightmostSetBit = xorResult & -xorResult;
        int xorSet = 0, xorNotSet = 0;
        
        for (int i = 1; i <= n; i++)
            if (i & rightmostSetBit)
                xorSet ^= i;
            else xorNotSet ^= i;

        for (int num : nums)
            if (num & rightmostSetBit)
                xorSet ^= num;
            else xorNotSet ^= num;
        
        for (int num : nums)
            if (num == xorSet)
                return {xorSet, xorNotSet};

        return {xorNotSet, xorSet};
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
        vector<int> ans = ob.findErrorNums(nums);
        cout << ans[0] << ' ' << ans[1] << endl;
    }

    return 0;
}

/* Sample Input
2
4
1 2 2 4
2
1 1

Sample Output
2 3
1 2

*/