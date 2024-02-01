// LC DCC 2024/01/05
// 300. Longest Increasing Subsequence
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        // // Approach 1: T.C. = O(N ^ 2), S.C. = O(N)
        // int n = nums.size();
        // vector<int> dp(n, 1);

        // for (int i = 1; i < n; ++i)
        //     for (int j = 0; j < i; ++j)
        //         if (nums[i] > nums[j])
        //             dp[i] = max(dp[i], dp[j] + 1);

        // return *max_element(dp.begin(), dp.end());

        // Approach 2: T.C. = O(N log N), S.C. = O(N)
        vector<int> tails(nums.size(), 0);
        int size = 0;

        for (int x: nums) {
            int i = 0, j = size;
            while (i != j) {
                int m = (i + j) / 2;
                if (tails[m] < x)
                    i = m + 1;
                else j = m;
            }
            tails[i] = x;
            if (i == size) ++size;
        }

        return size;
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
        cout << ob.lengthOfLIS(nums) << endl;
    }

    return 0;
}

/* Sample Input:
3
8
10 9 2 5 3 7 101 18
6
0 1 0 3 2 3
7
7 7 7 7 7 7 7

Sample Output:
4
4
1

*/