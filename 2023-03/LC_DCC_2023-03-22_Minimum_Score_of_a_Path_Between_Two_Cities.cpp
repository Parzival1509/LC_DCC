// LC DCC 2023/03/22
// 2492. Minimum Score of a Path Between Two Cities
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>> &graph, vector<int> &vis, vector<int> &ans) {
        vis[node] = 0;
        for(auto&child: graph[node]) {
            if(vis[child.first]) {
                ans.push_back(child.first);
                dfs(child.first, graph, vis, ans);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>> &roads) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto &road: roads) {
            graph[road[0]-1].push_back({road[1]-1, road[2]});
            graph[road[1]-1].push_back({road[0]-1, road[2]});
        }
        vector<int> vis(n, 1), ans;
        dfs(0, graph, vis, ans);
        int res = 1e9;
        for(int i=0; i<ans.size(); i++)
            for(auto &child: graph[ans[i]])
                res = min(res, child.second);
        return res;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n, num;
        cin>>n>>num;
        vector<vector<int>> roads;
        for(int i=0; i<num; i++) {
            vector<int> tmp(3);
            cin>>tmp[0]>>tmp[1]>>tmp[2];
            roads.push_back(tmp);
        }
        cout<<ob.minScore(n, roads)<<endl;
    }
    return 0;
}

/* Sample Input:
2
4 4
1 2 9
2 3 6
2 4 5
1 4 7
4 3
1 2 2
1 3 4
3 4 7

Sample Output:
5
2

*/