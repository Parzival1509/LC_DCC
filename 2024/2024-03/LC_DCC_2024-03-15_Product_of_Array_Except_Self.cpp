// LC DCC 2024/03/15
// 238. Product of Array Except Self
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // // Approach 1: Using suffix and prefix prdoucts
        // // T.C. = O(N), S.C. = O(N)
        // vector<int> prefix(n, 1), suffix(n, 1), ans(n);

        // for (int i = 1; i < n; ++i)
        //     prefix[i] = prefix[i - 1] * nums[i - 1];

        // for (int i = n - 2; i >= 0; --i)
        //     suffix[i] = suffix[i + 1] * nums[i + 1];

        // for (int i = 0; i < n; ++i)
        //     ans[i] = prefix[i] * suffix[i];

        // Approach 2:
        // T.C. = O(N), S.C. = O(1)
        vector<int> ans(n, 0);
        int product = 1, zeroes = 0;

        for (int num : nums) {
            if (num == 0) {
                zeroes++;
                if (zeroes > 1)
                    return ans;
                continue;
            }
            product *= num;
        }

        if (zeroes == 1) {
            for (int i = 0; i < n; i++)
                ans[i] = nums[i] == 0 ? product : 0;
        }
        else {
            for (int i = 0; i < n; i++)
                ans[i] = product / nums[i];
        }
        
        return ans;
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
        vector<int> ans = ob.productExceptSelf(nums);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
4
1 2 3 4
5
-1 1 0 -3 3

Sample Output
24 12 8 6 
0 0 9 0 0 

*/