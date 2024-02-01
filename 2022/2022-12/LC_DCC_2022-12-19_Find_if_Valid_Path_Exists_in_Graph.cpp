// LC DCC 2022/12/19
// 1971. Find if Path Exists in Graph
// Easy

#include <bits/stdc++.h>
using namespace std;

// Good T.C.
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> root(n, 0);
        for(int i = 0; i < n; i++)
            root[i] = i;
        for(auto& e: edges) {
            int i = find(root, e[0]);
            int j = find(root, e[1]);
            if(i != j) root[j] = i;
        }
        return find(root, source) == find(root, destination);
    }

    int find(vector<int>& root, int i) {
        if (root[i] == i) return i;
        root[i] = find(root, root[i]);
        return root[i];
    }
};

// // Baijnath's Sol
// class Solution {
// public:
//     unordered_map<int,vector<int> > ump;
//     bool validPath(int n, vector<vector<int>>& edges, int start, int destination) {
//         for(auto x: edges) {
//             vector<int> temp=x;
//             int u=temp[0];
//             int v=temp[1];
//             ump[u].push_back(v);
//             ump[v].push_back(u);
//         }
//         int N=ump.size();
//         vector<bool> vis(N+1, false);
//         queue<int> q;
//         q.push(start);
//         vis[start]=true;
//         while(!q.empty()) {
//             int curr=q.front();
//             q.pop();
//             vector<int> temp=ump[curr];
//             for(int i=0; i<temp.size(); i++) {
//                 int ver=temp[i];
//                 if(!vis[ver]) {
//                     q.push(ver);
//                     vis[ver]=true;    
//                 }
//             } 
//         }
//         return vis[destination];
//     }
// };

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<vector<int>> edges(n);
        for(int i=0; i<n; i++)
            cin>>edges[i][0]>>edges[i][1];
        int source, destination;
        cin>>source>>destination;
        cout<<ob.validPath(n, edges, source, destination)<<endl;
    }
}

/* Sample Input
2
3
0 1
1 2
2 0
0 2
6
0 1
0 2
3 5
5 4
4 3
0 5

Sample Output
1 1 0 
1 1 1 0 
1 1 4 2 1 1 0 0 

*/