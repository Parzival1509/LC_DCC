// LC DCC 2024/04/28
// 834. Sum of Distances in Tree
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> count;
    vector<int> res;

    void dfs(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                res[node] += res[child] + count[child];
            }
        }
    }

    void dfs2(int node, int parent) {
        for (int child : graph[node])
            if (child != parent) {
                res[child] =
                    res[node] - count[child] + (count.size() - count[child]);
                dfs2(child, node);
            }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.clear();
        count = vector<int>(n, 1);
        res = vector<int>(n, 0);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1);
        dfs2(0, -1);

        return res;
    }
};

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges(E, {0, 0});
        for(int i = 0; i < E; i++)
            cin >> edges[i][0] >> edges[i][1];

        Solution ob;
        vector<int> ans = ob.sumOfDistancesInTree(V, edges);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
3

1 0

2 1
1 0

6 5
0 1
0 2
2 3
2 4
2 5


Sample Output
0 
1 1 
8 12 6 10 10 10 

*/