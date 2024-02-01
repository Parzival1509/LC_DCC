// LC DCC 2023/02/08
// 45. Jump Game II
// Medium

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, n = int(nums.size()), curEnd = 0, curFar = 0;
        
        for(int i=0; i<n-1; ++i) {
            curFar = max(curFar, i + nums[i]);
            if(i == curEnd) {
                ans++;
                curEnd = curFar;
                if(curEnd >= n-1) break;
            }
        }
        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        cout<<ob.jump(nums)<<endl;
    }
    return 0;
}

/* Sample Input:
2
5
2 3 1 1 4
5
2 3 1 0 4

Sample Output:
2
2

*/