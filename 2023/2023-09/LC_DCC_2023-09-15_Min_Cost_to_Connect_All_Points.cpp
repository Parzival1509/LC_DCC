// LC DCC 2023/09/15
// 1584. Min Cost to Connect All Points
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> parent;
        vector<pair<int, pair<int, int>>> edges;
        int n = points.size();

        for(int i = 0; i < n; ++i)
            parent.push_back(i);

        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, {i, j}});
            }

        sort(edges.begin(), edges.end());

        int min_cost = 0, num_edges = 0;
        for(auto& edge : edges) {
            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if(find(parent, u) != find(parent, v)) {
                unionSets(parent, u, v);
                min_cost += cost;
                num_edges++;
            }

            if(num_edges == n - 1)
                break;
        }

        return min_cost;
    }

private:
    int find(vector<int>& parent, int x) {
        if(parent[x] == x) return x;
        
        parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    void unionSets(vector<int>& parent, int x, int y) {
        parent[find(parent, x)] = find(parent, y);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int> (2, 0));
        for(int i = 0; i < n; i++)
            cin >> points[i][0] >> points[i][1];
        cout << ob.minCostConnectPoints(points) << endl;
    }

    return 0;
}

/* Sample Input:
2
5
0 0
2 2
3 10
5 2
7 0
3
3 12
-2 5
-4 1

Sample Output:
20
18

*/