// LC DCC 2024/06/30
// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
// Hard

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i=0; i<n; i++)
            parent[i] = i;
    }
    
    int Find(int x) {
        return parent[x] = (parent[x] == x? x: Find(parent[x]));
    }
    
    bool Union(int x, int y) {
        int xset = Find(x), yset = Find(y);
        if(xset != yset) {
            rank[xset] < rank[yset]? parent[xset] = yset: parent[yset] = xset;
            rank[xset] += (rank[xset] == rank[yset]);
            return true;
        }
        return false;
    }
};

class Solution {
public:    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [&](auto const &a, auto const &b) {
            return a[0] > b[0];
        });

        DSU dsu_alice(n+1);
        DSU dsu_bob(n+1);

        int removed_edge = 0, alice_edges = 0, bob_edges = 0;
        for(auto edge: edges) {
            // Both Alice & Bob
            if(edge[0] == 3) {
                if(dsu_alice.Union(edge[1], edge[2])) {
                    dsu_bob.Union(edge[1], edge[2]);
                    alice_edges++;
                    bob_edges++;
                }
                else removed_edge++;
            }

            //Only Bob
            else if(edge[0] == 2) {
                if(dsu_bob.Union(edge[1], edge[2])) bob_edges++;
                else removed_edge++;
            }

            // Only Alice
            else {
                if(dsu_alice.Union(edge[1], edge[2])) alice_edges++;
                else removed_edge++;
            }
        }

        return (bob_edges == n-1 && alice_edges == n-1)? removed_edge: -1;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> edges(e, {0, 0, 0});
        for(int i = 0; i < e; i++)
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        cout << ob.maxNumEdgesToRemove(n, edges) << endl;
    }

    return 0;
}

/* Sample Input
3

4 6
3 1 2
3 2 3
1 1 3
1 2 4
1 1 2
2 3 4

4 4
3 1 2
3 2 3
1 1 4
2 1 4

4 3
3 2 3
1 1 2
2 3 4


Sample Output
2
0
-1

*/