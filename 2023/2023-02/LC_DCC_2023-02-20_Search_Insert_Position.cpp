// LC DCC 2023/02/20
// 35. Search Insert Position
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        if(target > nums[r]) return nums.size();
        if(target < nums[0]) return 0;

        while(l <= r) {
            mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) l = mid+1;
            else r = mid-1;
        }

        if(nums[mid] < target) return mid+1;
        return mid;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n, target;
        cin>>n>>target;
        vector<int> nums(n);
        for(auto &i: nums)
            cin>>i;
        cout<<ob.searchInsert(nums, target)<<endl;
    }
    return 0;
}

/* Sample Input:
3
4 5
1 3 5 6
4 2
1 3 5 6
4 7
1 3 5 6

Sample Output:
2
1
4

*/