// LC DCC 2023/02/21
// 540. Single Element in a Sorted Array
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n-1, mid;
        while(lo < hi) {
            mid = (lo+hi)/2;
            // cout<<lo<<' '<<mid<<' '<<hi<<' '<<nums[mid]<<endl;
            if((hi-mid)%2 == 0 and mid<n-1 and nums[mid] != nums[mid+1])
                hi = mid;
            else if((hi-mid)%2 == 1 and mid<n-1 and nums[mid] == nums[mid+1])
                hi = mid-1;
            else lo = mid+1;
        }
        // cout<<lo<<' '<<mid<<' '<<hi<<' '<<nums[mid]<<endl;
        mid = (lo+hi)/2;
        return nums[mid];
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int &i: nums)
            cin>>i;
        cout<<ob.singleNonDuplicate(nums)<<endl;
    }
    return 0;
}

/* Sample Input:
2
9
1 1 2 3 3 4 4 8 8
7
3 3 7 7 10 11 11

Sample Output:
2
10

*/