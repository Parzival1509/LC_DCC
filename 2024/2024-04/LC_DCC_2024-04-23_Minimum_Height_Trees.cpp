// LC DCC 2024/04/23
// 310. Minimum Height Trees
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
    
        vector<vector<int>> adjacency_list(n);
        vector<int> degree(n, 0);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjacency_list[u].push_back(v);
            adjacency_list[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        queue<int> leaves;
        for (int i = 0; i < n; ++i)
            if (degree[i] == 1) leaves.push(i);
        
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int leavesCount = leaves.size();
            remainingNodes -= leavesCount;
            for (int i = 0; i < leavesCount; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : adjacency_list[leaf]) {
                    if (--degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result;
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
        vector<int> ans = ob.findMinHeightTrees(V, edges);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
2

4 3
1 0
1 2
1 3

6 5
3 0
3 1
3 2
3 4
5 4

Sample Output
1 
3 4 

*/