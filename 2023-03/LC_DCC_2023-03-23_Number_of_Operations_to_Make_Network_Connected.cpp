// LC DCC 2023/03/23
// 1319. Number of Operations to Make Network Connected
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    void dfs(int node,vector<vector<int>>&g,vector<int>&vis){
        vis[node] = 0;
        for(auto&child: g[node])
            if(vis[child]) dfs(child, g, vis);
    }

    int makeConnected(int n, vector<vector<int>>& conn) {
        if(conn.size() < n-1) return -1;

        vector<vector<int>> g(n);
        for(int i=0; i<conn.size(); i++) {
            g[conn[i][0]].push_back(conn[i][1]);
            g[conn[i][1]].push_back(conn[i][0]);
        }

        vector<int> vis(n, 1);
        int connectedComponents = 0;
        for(int i=0; i<n; i++) 
            if(vis[i]) {
                dfs(i, g, vis);
                connectedComponents++;
            }

        return connectedComponents-1;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n, ct;
        cin>>n>>ct;
        vector<vector<int>> conn;
        for(int i=0; i<ct; i++) {
            vector<int> tmp;
            cin>>tmp[0]>>tmp[1];
            conn.push_back(tmp);
        }
        cout<<ob.makeConnected(n, conn)<<endl;
    }
    return 0;
}

/* Sample Input:
3
4 3
0 1
0 2
1 2
6 5
0 1
0 2
0 3
1 2
1 3
6 4
0 1
0 2
0 3
1 2

Sample Output:
1
2
-1

*/