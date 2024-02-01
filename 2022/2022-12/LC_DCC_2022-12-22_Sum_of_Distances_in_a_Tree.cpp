// LC DCC 2022/12/22
// 834. Sum of Distances in Tree
// Hard

#include <bits/stdc++.h>
using namespace std;

// Baijnath's Sol
class Solution {
public:
    vector<int> adj[30007], sub, dep, sum;
    int n;
    void dfs(int u, int par= -1) {
        sub[u] = 1;
        for(auto x: adj[u]){
            if(x==par) continue;
            dep[x] = dep[u]+1;
            dfs(x, u);
            sub[u] += sub[x];
        }
    }

    void dfs2(int u, int par=-1) {
        for(auto x: adj[u]) {
            if(x==par) 
                continue;
            sum[x] = sum[u]-sub[x]+(n-sub[x]);
            dfs2(x, u);
        }
    }
 
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n=N;
        sub.resize(n+1);
        dep.resize(n+1);
        sum.resize(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0);
        for(int i=0; i<n; i++)
            sum[0] += dep[i];
        dfs2(0);
        return sum;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<vector<int>> edges(n-1, vector<int> (2, 0));
        for(int i=0; i<n-1; i++)
            cin>>edges[i][0]>>edges[i][1];
        vector<int> ans=ob.sumOfDistancesInTree(n, edges);
        for(auto el: ans)
            cout<<el<<' ';
        cout<<endl;
    }
}

/* Sample Input
3
1
2
1 0
6
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