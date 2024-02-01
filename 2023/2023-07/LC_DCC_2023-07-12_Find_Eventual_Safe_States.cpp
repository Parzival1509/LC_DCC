// LC DCC 2023/07/12
// 802. Find Eventual Safe States
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& dfsVisited, vector<int>& check) {
        vis[node] = 1;
        dfsVisited[node] = 1;
        check[node] = 0;
        for(int neighbour: graph[node]) {
            if(!vis[neighbour]) {
                if(dfs(neighbour, graph, vis, dfsVisited, check))
                    return true;
            }
            else if(dfsVisited[neighbour])
                return true;
        }

        check[node] = 1;
        dfsVisited[node] = 0;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans, vis(n), dfsVisited(n), check(n);

        for(int i = 0 ; i < n ; i++)
            if(!vis[i])
                dfs(i, graph, vis, dfsVisited, check);

        for(int i = 0 ; i < n ; i++)
            if(check[i] == 1)
                ans.push_back(i);

        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n;
        cin >> n;
        vector<vector<int>> graph;
        for(int i = 0; i < n; i++) {
            int m;
            cin >> m;
            vector<int> tmp(m, 0);
            for(int &i: tmp)
                cin >> i;
            graph.push_back(tmp);
        }

        vector<int> ans = ob.eventualSafeNodes(graph);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }
    
    return 0;
}

/* Sample Input:
2

7
2 1 2
2 2 3
1 5
1 0
1 5
0
0

5
4 1 2 3 4
2 1 2
2 3 4
2 0 4
0

Sample Output:
2 4 5 6 
4 

*/