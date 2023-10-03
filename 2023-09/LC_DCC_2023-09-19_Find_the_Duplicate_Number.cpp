// LC DCC 2023/09/19
// 287. Find the Duplicate Number
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // // Approach 1: Using slow and fast pointers
        // int slow = nums[nums[0]], fast = nums[nums[nums[0]]];
        
        // while(slow != fast) {
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];
        // }
        
        // slow = nums[0];
        // while(slow != fast) {
        //     slow = nums[slow];
        //     fast = nums[fast];
        // }
        
        // return fast;

        // Approach 2: Using Binary Search
        int n = nums.size(), lo = 1, hi = n - 1;
        while(lo < hi) {
            int mid = (hi + lo) / 2;
            int ct = 0;
            for(int i = 0; i < n; i++)
                if(nums[i] <= mid)
                    ct++;
                
            if(ct <= mid) lo = mid + 1;
            else hi = mid;
        }

        return lo;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n + 1, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.findDuplicate(nums) << endl;
    }

    return 0;
}

/* Sample Input:
2
4
1 3 4 2 2
4
3 1 3 4 2

Sample Output:
2
3

*/