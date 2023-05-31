// LC DCC 2023/05/22
// 347. Top K Frequent Elements
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> res;
        for(int i = 0; i < n; i++)
            mp[nums[i]]++;
        
        priority_queue<pair<int, int>> m;
        for(auto i: mp)
            m.push(make_pair(i.second, i.first));
        
        for(int i = 0; i < k; i++) {
            res.push_back(m.top().second);
            m.pop();
        }
      
        return res;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int> nums(n, 0);
        for(auto &i: nums)
            cin>>i;
        vector<int> ans = ob.topKFrequent(nums, k);
        for(auto i: ans)
            cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
6 2
1 1 1 2 2 3
1 1
1

Sample Output:
1 2 
1 

*/