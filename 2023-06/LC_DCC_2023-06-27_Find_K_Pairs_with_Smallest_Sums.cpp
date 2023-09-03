// LC DCC 2023/06/27
// 373. Find K Pairs with Smallest Sums
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        
        // Approach 1: Using Min Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int x: nums1)
            pq.push({x + nums2[0], 0});

        while(k-- && !pq.empty()) {
            int sum = pq.top().first;
            int pos = pq.top().second;

            ans.push_back({sum - nums2[pos], nums2[pos]});
            pq.pop();

            if(pos + 1 < m)
                pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
        }

        // // Approach 2: Using Max Heap
        // priority_queue<pair<int, pair<int, int>>> pq;

        // for(int i = 0; i < n; i++)
        //     for(int j = 0; j < m; j++) {
        //         int sum = nums1[i] + nums2[j];
        //         if(pq.size() < k)
        //             pq.push({sum, {nums1[i], nums2[j]}});
        //         else if(sum < pq.top().first) {
        //             pq.pop();
        //             pq.push({sum, {nums1[i], nums2[j]}});
        //         }
        //         else break; 
        //     }

        // while(!pq.empty()) {
        //     ans.push_back({pq.top().second.first, pq.top().second.second});
        //     pq.pop();
        // }

        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> nums1(n, 0), nums2(m, 0);
        for(int &i: nums1)
            cin >> i;
        for(int &i: nums2)
            cin >> i;
        vector<vector<int>> ans = ob.kSmallestPairs(nums1, nums2, k);
        for(auto pr: ans)
            cout << pr[0] << ' ' << pr[1] << endl;
        cout << endl;
    }
    return 0;
}

/* Sample Input:
3

3 3 3
1 7 11
2 4 6

3 3 2
1 1 2
1 2 3

2 1 3
1 2
3

Sample Output:
1 2
1 4
1 6

1 1
1 1

1 3
2 3


*/