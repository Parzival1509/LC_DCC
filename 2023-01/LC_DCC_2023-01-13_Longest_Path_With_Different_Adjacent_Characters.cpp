// LC DCC 2023/01/13
// 2246. Longest Path With Different Adjacent Characters
// Hard

#include <bits/stdc++.h>
using namespace std;

// DFS APPROACH
class Solution {
public:
        int longestPath(vector<int>& parent, string s) {
        int n = s.size(), res = 0;
        vector<vector<int>> children(n, vector<int>());
        for(int i=1; i<n; ++i)
            children[parent[i]].push_back(i);
        dfs(children, s, res, 0);
        return res;
    }

    int dfs(vector<vector<int>>& children, string& s, int& res, int i) {
        int big1 = 0, big2 = 0;
        for (int& j: children[i]) {
            int cur = dfs(children, s, res, j);
            if(s[i] == s[j]) continue;
            if(cur > big2) big2 = cur;
            if(big2 > big1) swap(big1, big2);
        }
        res = max(res, big1 + big2 + 1);
        return big1 + 1;
    }
};

// // BFS APPROACH
// int find(int i, vector<bool>& vis, vector<vector<int>>& adj){
//     vector<bool> v(vis.size(), false);
//     v[i] = true;
//     queue<int>q;
//     q.push(i);
//     int k;
//     int l = 0;
//     while(!q.empty()) {
//         int j = q.front();
//         if(q.size() == 1) k = q.front();
//         q.pop();
//         for(int t=0; t<adj[j].size(); t++) {
//             if(!v[adj[j][t]]) q.push(adj[j][t]);
//             v[adj[j][t]] = true;
//         }
//     }
//     q.push(k);
//     while(!q.empty()) {
//         int n = q.size();
//         while(n--) {
//             int j = q.front();
//             vis[j]=true;
//             q.pop();
//             for(int t=0; t<adj[j].size(); t++) {
//                 if(!vis[adj[j][t]]) q.push(adj[j][t]);
//                 vis[adj[j][t]] = true;
//             }
//         }
//         l++;
//     }
//     return l;
// }

// int longestPath(vector<int>& parent, string s) {
//     vector<vector<int>> adj(parent.size());
//     unordered_set<int> st;
//     for(int i=1; i<parent.size(); i++){
//         if(s[parent[i]] != s[i]){
//             adj[parent[i]].push_back(i);
//             adj[i].push_back(parent[i]);
//             st.insert(i);
//             st.insert(parent[i]);
//         }
//     }
//     if(st.size() == 0) return 1;
//     int n = adj.size();
//     vector<bool> vis(n, false);
//     int ans = 0;
//     for(auto &i: st)
//         if(!vis[i])
//             ans=max(ans, find(i, vis, adj));
//     return ans;
// }

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        
    }
    return 0;
}

/* Sample Input
2
parent = [-1,0,0,0], s = "aabc"
parent = [-1,0,0,1,1,2], s = "abacbe"

Sample Output
3
3

*/