// LC DCC 2023/02/12
// 2477. Minimum Fuel Cost to Report to the Capital
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// // Approach 1: DFS
// class Solution {
// public:
//     ll fuel = 0;

//     ll dfs(int node, int parent, vector<vector<int>>& adj, int& seats) {
//         // The node itself has one representative.
//         int representatives = 1;
//         for (auto& child : adj[node]) {
//             if (child != parent) {
//                 // Add count of representatives in each child subtree to the parent subtree.
//                 representatives += dfs(child, node, adj, seats);
//             }
//         }

//         if (node != 0) {
//             // Count the fuel it takes to move to the parent node.
//             // Root node does not have any parent so we ignore it.
//             fuel += ceil((double)representatives / seats);
//         }
//         return representatives;
//     }

//     ll minimumFuelCost(vector<vector<int>>& roads, int seats) {
//         int n = roads.size() + 1;
//         vector<vector<int>> adj(n);
//         for (auto& road : roads) {
//             adj[road[0]].push_back(road[1]);
//             adj[road[1]].push_back(road[0]);
//         }
//         dfs(0, -1, adj, seats);
//         return fuel;
//     }
// };

// Approach 2: BFS
class Solution {
public:
    ll bfs(int n, vector<vector<int>>& adj, vector<int>& degree, int& seats) {
        queue<int> q;
        for (int i = 1; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        vector<int> representatives(n, 1);
        ll fuel = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            fuel += ceil((double)representatives[node] / seats);
            for (auto& neighbor : adj[node]) {
                degree[neighbor]--;
                representatives[neighbor] += representatives[node];
                if (degree[neighbor] == 1 && neighbor != 0) {
                    q.push(neighbor);
                }
            }
        }
        return fuel;
    }

    ll minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        vector<int> degree(n);

        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
            degree[road[0]]++;
            degree[road[1]]++;
        }

        return bfs(n, adj, degree, seats);
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> roads(n, vector<int> (2, 0));
        for(int i=0; i<n; i++)
            cin>>roads[i][0]>>roads[i][1];
        int seats;
        cin>>seats;
        cout<<ob.minimumFuelCost(roads, seats)<<endl;
    }
    return 0;
}

/* Sample Input:
3
0
1
3
0 1
0 2
0 3
5
6
3 1
3 2
1 0
0 4
0 5
4 6
2

Sample Output:
0
3
7

*/