// LC DCC 2023/11/11
// 2642. Design Graph With Shortest Path Calculator
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Graph {
public:
    // Adjacency list to represent the graph
    vector<vector<pair<int, int>>> adjacencyList;

    // Constructor to initialize the graph with nodes and edges
    Graph(int n, vector<vector<int>>& edges) {
        adjacencyList.resize(n);
        for(auto edge: edges)
            adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
    }

    // Add a new edge to the graph
    void addEdge(vector<int> edge) {
        adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
    }

    // Find the shortest path between two nodes using Dijkstra's algorithm
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }

private:
    int dijkstra(int start, int end) {
        int n = adjacencyList.size();
        vector<int> distances(n, INT_MAX);
        distances[start] = 0;

        // Priority queue to efficiently retrieve the node with the minimum distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});

        while(!pq.empty()) {
            int currentNode = pq.top().second;
            int currentCost = pq.top().first;
            pq.pop();

            // Skip if a shorter path has already been found
            if(currentCost > distances[currentNode])
                continue;

            // If found the target node then return the cost
            if(currentNode == end) return currentCost;

            // Explore neighbors and update distances
            for(auto edge: adjacencyList[currentNode]) {
                int neighbor = edge.first, edgeLength = edge.second;
                int newRouteCost = edgeLength + distances[currentNode];

                // Update distance if a shorter route is found
                if(distances[neighbor] > newRouteCost) {
                    distances[neighbor] = newRouteCost;
                    pq.push({newRouteCost, neighbor});
                }
            }
        }

        // Return the minimum distance or -1 if no path exists
        return ((distances[end] == INT_MAX)? -1: distances[end]);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
*/

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input:

Sample Output:

*/