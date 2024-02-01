// LC DCC 2023/06/28
// 1514. Path with Maximum Probability
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Bellman-Ford
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }

        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (auto x : adj[curr]) {
                int node = x.first;
                double prob = x.second;
                double newProb = dist[curr] * prob;
                
                if (newProb > dist[node]) {
                    dist[node] = newProb;
                    q.push(node);
                }
            }
        }
        
        return dist[end];
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, e, start, end;
        cin >> n >> e >> start >> end;
        vector<vector<int>> edges(e, vector<int> (2, 0));
        for(int i = 0; i < e; i++)
            cin >> edges[i][0] >> edges[i][1];

        vector<double> succProb(e, 0.0);
        for(int i = 0; i < e; i++)
            cin >> succProb[i];

        cout << ob.maxProbability(n, edges, succProb, start, end) << endl;
    }
    return 0;
}

/* Sample Input:
3

3 3 0 2
0 1
1 2
0 2
0.5 0.5 0.2

3 3 0 2
0 1
1 2
0 2
0.5 0.5 0.3

3 1 0 2
0 1
0.5

Sample Output:
0.25
0.3
0

*/