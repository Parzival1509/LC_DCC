// LC DCC 2023/08/08
// 33. Search in Rotated Sorted Array
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), lo = 0, hi = n - 1;

        while(lo <= hi) {
            int mid = (lo + hi) / 2, x = nums[mid];
            if(x == target) return mid;

            if(nums[lo] <= x) {
                if(target >= nums[lo] && target <= x)
                    hi = mid - 1;
                else lo = mid + 1;
            }
            else {
                if(target >= x && target <= nums[hi])
                    lo = mid + 1;
                else hi = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n, target;
        cin >> n >> target;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.search(nums, target) << endl;
    }
    
    return 0;
}

/* Sample Input:
3
7 0
4 5 6 7 0 1 2
7 3
4 5 6 7 0 1 2
1 0
1

Sample Output:
4
-1
-1

*/