// LC DCC 2023/02/11
// 1129. Shortest Path with Alternating Colors
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& redEdge : redEdges)
            adj[redEdge[0]].push_back({redEdge[1], 0});
        
        for (auto& blueEdge : blueEdges)
            adj[blueEdge[0]].push_back(make_pair(blueEdge[1], 1));

        vector<int> answer(n, -1);
        vector<vector<bool>> visit(n, vector<bool>(2));
        queue<vector<int>> q;

        // Start with node 0, with number of steps as 0 and undefined color -1.
        q.push({0, 0, -1});
        visit[0][1] = visit[0][0] = true;
        answer[0] = 0;

        while (!q.empty()) {
            auto element = q.front();
            int node = element[0], steps = element[1], prevColor = element[2];
            q.pop();

            // for (auto& [neighbor, color] : adj[node]) {
            for (auto& childPair : adj[node]) {
                int neighbor = childPair.first, color = childPair.second;
                if (!visit[neighbor][color] && color != prevColor) {
                    visit[neighbor][color] = true;
                    q.push({neighbor, 1 + steps, color});
                    if (answer[neighbor] == -1)
                        answer[neighbor] = 1 + steps;
                }
            }
        }
        return answer;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n, r, b;
        cin>>n>>r>>b;
        vector<vector<int>> redEdges(r, vector<int> (2, 0)), blueEdges(b, vector<int> (2, 0));
        for(int i=0; i<r; i++)
            cin>>redEdges[i][0]>>redEdges[i][1];
        for(int i=0; i<b; i++)
            cin>>blueEdges[i][0]>>blueEdges[i][1];

        vector<int> ans = ob.shortestAlternatingPaths(n, redEdges, blueEdges);
        for(auto el: ans)
            cout<<el<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
3 2 0
0 1
1 2
3 1 1
0 1
2 1

Sample Output:
0 1 -1 
0 1 -1 

*/