// LC DCC 2023/05/24
// 2542. Maximum Subsequence Score
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        for(int i = 0; i < nums2.size(); i++)
            v.push_back({nums2[i], i});
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
            return a.first > b.first;
        });

        long long rv = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < nums1.size(); i++) {
            int val = nums1[v[i].second];
            if(pq.size() < k-1) {
                pq.push(val);
                sum += val;
            }
            else {
                rv = max(rv, (sum + val) * v[i].first);
                sum += val;
                pq.push(val);
                sum -= pq.top();
                pq.pop();
            }
        }

        return rv;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int> nums1(n, 0), nums2(n, 0);
        for(auto &i: nums1)
            cin>>i;
        for(auto &i: nums2)
            cin>>i;
        cout<<ob.maxScore(nums1, nums2, k)<<endl;
    }
    return 0;
}

/* Sample Input:
2
4 3
1 3 3 2
2 1 3 4
5 1
4 2 3 1 1
7 5 10 9 6

Sample Output:
12
30

*/