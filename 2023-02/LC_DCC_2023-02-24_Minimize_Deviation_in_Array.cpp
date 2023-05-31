// LC DCC 2023/02/24
// 1675. Minimize Deviation in Array
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int m = INT_MAX, ans = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] & 1) {
                pq.push(nums[i]*2);
                m = min(m, nums[i]*2);
            }
            else {
                pq.push(nums[i]);
                m = min(m, nums[i]);
            }
        }
        
        while(!pq.empty()) {
            int top = pq.top();
            pq.pop();
            ans = min(ans, top-m);
            if(top & 1) break;
            m = min(m, top/2);
            pq.push(top/2);
        }
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
        cout<<ob.minimumDeviation(nums)<<endl;
    }
    return 0;
}

/* Sample Input:
3
4
1 2 3 4
5
4 1 5 20 3
3
2 10 8

Sample Output:
1
3
3

*/