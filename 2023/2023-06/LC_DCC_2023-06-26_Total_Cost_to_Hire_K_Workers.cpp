// LC DCC 2023/06/26
// 2462. Total Cost to Hire K Workers
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        long long cost = 0;
        int count = 0, low = 0, high = costs.size()-1;

        while(count < k) {
            while((pq1.size() < candidates) && (low <= high)) {
                pq1.push(costs[low]);
                low += 1;
            }

            while((pq2.size() < candidates) && (high >= low)) {
                pq2.push(costs[high]);
                high -= 1;
            }

            int cost1 = (pq1.size() > 0)? pq1.top(): INT_MAX;
            int cost2 = (pq2.size() > 0)? pq2.top(): INT_MAX;

            if(cost1 <= cost2) {
                cost += cost1;
                pq1.pop();
            }
            else {
                cost += cost2;
                pq2.pop();
            }
            count += 1;
        }

        return cost;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, k, candidates;
        cin >> n >> k >> candidates;
        vector<int> costs(n, 0);
        for(int &i: costs)
            cin >> i;
        cout << ob.totalCost(costs, k, candidates) << endl;
    }
    return 0;
}

/* Sample Input:
2
9 3 4
17 12 10 2 7 2 11 20 8
4 3 3
1 2 4 1

Sample Output:
11
4

*/