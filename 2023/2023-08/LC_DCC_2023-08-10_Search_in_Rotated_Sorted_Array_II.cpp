// LC DCC 2023/08/10
// 81. Search in Rotated Sorted Array II
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(nums[mid] == target) return true;

            // With duplicates, this case is possible
            if((nums[lo] == nums[mid]) && (nums[mid] == nums[hi])) {
                lo++;
                hi--;
            }
            // First half is in order
            else if(nums[lo] <= nums[mid]) {
                // Target is in first half
                if((nums[lo] <= target) && (nums[mid] > target))
                    hi = mid - 1;
                else lo = mid + 1;
            }
            // Second half is in order
            else {
                // Target is in second half
                if((nums[mid] < target) && (nums[hi] >= target))
                    lo = mid + 1;
                else hi = mid - 1;
            }
        }

        return false;
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
        if(ob.search(nums, target)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }
    
    return 0;
}

/* Sample Input:
3
7 0
2 5 6 0 0 1 2
7 3
2 5 6 6 0 1 2
5 0
1 0 1 1 1

Sample Output:
true 
false 
true 

*/