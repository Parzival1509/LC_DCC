// LC DCC 2023/04/01
// 704. Binary Search
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        while(l <= r) {
            mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, target;
        cin>>n>>target;
        vector<int> nums(n);
        for(auto &i: nums)
            cin>>i;
        cout<<ob.search(nums, target)<<endl;
    }
    return 0;
}

/* Sample Input:
2
6 9
-1 0 3 5 9 12
6 2
-1 0 3 5 9 12

Sample Output:
4
-1

*/