// LC DCC 2024/03/31
// 2444. Count Subarrays With Fixed Bounds
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll countSubarrays(vector<int>& nums, int mink, int maxk) {
        ll res = 0;
        bool minfound = false, maxfound = false;
        int start = 0, minstart = 0, maxstart = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            if (num < mink || num > maxk) {
                minfound = false;
                maxfound = false;
                start = i + 1;
            }
            if (num == mink) {
                minfound = true;
                minstart = i;
            }
            if (num == maxk) {
                maxfound = true;
                maxstart = i;
            }

            if (minfound && maxfound)
                res += min(minstart, maxstart) - start + 1;
        }

        return res;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, mink, maxk;
        cin >> n >> mink >> maxk;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.countSubarrays(nums, mink, maxk) << endl;
    }

    return 0;
}

/* Sample Input
2
6 1 5
1 3 5 2 7 5
4 1 1
1 1 1 1

Sample Output
2
10

*/