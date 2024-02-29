// LC DCC 2024/02/23
// 787. Cheapest Flights Within K Stops
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int mk) {
        vector<vector<int>> dp(n, vector<int>(mk + 2, INT_MAX));
        vector<vector<pair<int, int>>> edges(n, vector<pair<int, int>>());
        for (int i = 0; i < flights.size(); i++)
            edges[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        
        queue<vector<int>> que;
        que.push({src, 0, 0});
        dp[src][0] = 0;
        while (!que.empty()) {
            int node = que.front()[0];
            int dis = que.front()[1];
            int k = que.front()[2];
            que.pop();
            // cout << node << endl;
            for (pair<int, int> child : edges[node])
                if (k <= mk &&
                    dp[child.first][k + 1] > dp[node][k] + child.second) {
                    dp[child.first][k + 1] = dp[node][k] + child.second;
                    que.push({child.first, dp[child.first][k + 1], k + 1});
                }
        }

        int ans = INT_MAX;
        for (int x : dp[dst])
            ans = min(ans, x);
        
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, f, src, dst, k;
        cin >> n >> f >> src >> dst >> k;
        vector<vector<int>> flights(f, {0, 0, 0});
        for(int i = 0; i < f; i++)
            cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
        cout << ob.findCheapestPrice(n, flights, src, dst, k) << endl;
    }

    return 0;
}

/* Sample Input
3
3 3 0 2 0
0 1 100
1 2 100
0 2 500
3 3 0 2 1
0 1 100
1 2 100
0 2 500
4 5 0 3 1
0 1 100
1 2 100
2 0 100
1 3 600
2 3 200

Sample Output
500
200
700

*/