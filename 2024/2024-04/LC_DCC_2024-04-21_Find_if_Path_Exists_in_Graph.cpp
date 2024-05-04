// LC DCC 2024/04/21
// 1971. Find if Path Exists in Graph
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, int destination, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
        if (node == destination)
            return true;

        visited.insert(node);
        for (int neighbor : graph[node])
            if (visited.find(neighbor) == visited.end())
                if (dfs(neighbor, destination, graph, visited))
                    return true;

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // unordered_set<int> visited;

        // // // Approach 1: DFS
        // // return dfs(source, destination, graph, visited);
        
        // // Approach 2: BFS
        // queue<int> q;
        // q.push(source);
        // visited.insert(source);
        
        // while (!q.empty()) {
        //     int node = q.front();
        //     q.pop();
        //     if (node == destination)
        //         return true;
            
        //     for (int neighbor : graph[node]) {
        //         if (visited.find(neighbor) == visited.end()) {
        //             visited.insert(neighbor);
        //             q.push(neighbor);
        //         }
        //     }
        // }
        
        // return false;

        // Approach 3: Using Standard Graph Algorithms
        vector<int> distances(n, INT_MAX);
        distances[source] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int currentDistance = current.first;
            int currentNode = current.second;
            
            if (currentNode == destination)
                return true;
            
            if (currentDistance > distances[currentNode])
                continue;
            
            for (int neighbor : graph[currentNode]) {
                int distance = currentDistance + 1;
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    pq.push({distance, neighbor});
                }
            }
        }
        
        return false;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int v, e, source, destination;
        cin >> v >> e >> source >> destination;

        vector<vector<int>> edges(e, {0, 0});
        for(int i = 0; i < e; i++)
            cin >> edges[i][0] >> edges[i][1];

        if(ob.validPath(v, edges, source, destination))
            cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}

/* Sample Input
2
3 3 0 2
0 1
1 2
2 0
6 5 0 5
0 1
0 2
3 5
5 4
4 3

Sample Output
true
false

*/