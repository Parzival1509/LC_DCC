// LC DCC 2023/08/19
// 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class UnionFind {
private:
    vector<int> f, rank;

public:
    UnionFind(int n) {
        rank = vector<int>(n, 1);
        f.resize(n);
        for (int i = 0; i < n; ++i) f[i] = i;
    }
    
    int Find(int x) {
        if(x == f[x]) return x;
        return f[x] = Find(f[x]);
    }
    
    void Union(int x, int y) {
        int fx = Find(x), fy = Find(y);
        if(fx == fy) return;

        if(rank[fx] > rank[fy]) swap(fx, fy);
        f[fx] = fy;
        if(rank[fx] == rank[fy]) rank[fy]++;
    }
};

class Solution {
private:
    int GetMST(int n, vector<vector<int>>& edges, int blockedge, int pre_edge = -1) {
        UnionFind uf(n);
        int weight = 0;
        if(pre_edge != -1) {
            weight += edges[pre_edge][2];
            uf.Union(edges[pre_edge][0], edges[pre_edge][1]);
        }

        for(int i = 0; i < edges.size(); ++i) {
            if (i == blockedge) continue;

            const auto& edge = edges[i];
            if(uf.Find(edge[0]) == uf.Find(edge[1])) continue;

            uf.Union(edge[0], edge[1]);
            weight += edge[2];
        }

        for(int i = 0; i < n; ++i)
            if(uf.Find(i) != uf.Find(0)) return 1e9+7;
        
        return weight;
    }

public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); ++i)
            edges[i].push_back(i);
        sort(edges.begin(), edges.end(), cmp);

        int origin_mst = GetMST(n, edges, -1);
        vector<int> critical, non_critical;

        for(int i = 0; i < edges.size(); ++i) {
            if(origin_mst < GetMST(n, edges, i))
                critical.push_back(edges[i][3]);
            else if(origin_mst == GetMST(n, edges, -1, i))
                non_critical.push_back(edges[i][3]);
        }

        return {critical, non_critical};
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(m, vector<int> (3, 0));
        for(int i = 0; i < m; i++)
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

        vector<vector<int>> ans = ob.findCriticalAndPseudoCriticalEdges(n, edges);
        for(auto el: ans) {
            for(int i: el)
                cout << i << ' ';
            cout << endl;
        }
    }

    return 0;
}

/* Sample Input:
2
5 7
0 1 1
1 2 1
2 3 2
0 3 2
0 4 3
3 4 3
1 4 6
4 4
0 1 1
1 2 1
2 3 1
0 3 1

Sample Output:
0 1 
2 3 4 5 

0 1 2 3 

*/