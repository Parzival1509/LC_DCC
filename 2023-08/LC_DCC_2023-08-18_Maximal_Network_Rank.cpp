// LC DCC 2023/08/18
// 1615. Maximal Network Rank
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        
        // Building the graph (adjacency list). 
        for(auto& road: roads) {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        
        int maximal = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // Sum of neighbors (connected cities) of both cities. 
                int network_rank = graph[i].size() + graph[j].size();
                
                // Reduce the rank by 1 in case the cities are connected to each other.
                if(graph[j].count(i))
                    --network_rank;
                
                // Maximal network rank is the maximum network rank possible.
                maximal = max(maximal, network_rank);
            }
        }

        return maximal;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> roads(m, vector<int> (2, 0));
        for(int i = 0; i < m; i++)
            cin >> roads[i][0] >> roads[i][1];

        cout << ob.maximalNetworkRank(n, roads) << endl;
    }

    return 0;
}

/* Sample Input:
3

4 4
0 1
0 3
1 2
1 3

5 6
0 1
0 3
1 2
1 3
2 3
2 4

8 6
0 1
1 2
2 3
2 4
5 6
5 7

Sample Output:
4
5
5

*/