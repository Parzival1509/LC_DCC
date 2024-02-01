// LC DCC 2023/03/21
// 2348. Number of Zero-Filled Subarrays
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long n = nums.size(), ans = 0, cnt = 0;
        for(int i = 0; i < n; i++)
            if(nums[i] == 0) cnt++;
            else {
                ans += ((long)(cnt*(cnt+1))/2);
                cnt = 0;
            }
        if(cnt != 0) ans += ((long)(cnt*(cnt+1))/2);
        return ans;
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
        for(int i=0; i<n; i++)
            cin>>nums[i];
        cout<<ob.zeroFilledSubarray(nums)<<endl;
    }
    return 0;
}

/* Sample Input:
3
8
1 3 0 0 2 0 0 4
6
0 0 0 2 0 0
3
2 10 200

Sample Output:
6
9
0

*/