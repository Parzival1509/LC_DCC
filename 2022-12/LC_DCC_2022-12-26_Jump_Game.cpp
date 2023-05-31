// LC DCC 2022/12/26
// 55. Jump Game
// Medium

#include <bits/stdc++.h>
using namespace std;

// Baijnath's Sol
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0, maxReach=0;
        while(i<nums.size() && i<=maxReach) {
            maxReach = max(i+nums[i], maxReach);
            i++;
        }
        if(i == nums.size())
            return true;
        return false;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        cout<<ob.canJump(nums)<<endl;
    }
}

/* Sample Input
2
5
2 3 1 1 4
5
3 2 1 0 4

Sample Output
1
0

*/