// LC DCC 2023/09/17
// 847. Shortest Path Visiting All Nodes
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    class tuple {
    public:
        int node;
        int mask;
        int cost;

        tuple(int node, int mask, int cost) {
            this->node = node;
            this->mask = mask;
            this->cost = cost;
        }
    };
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple> q;
        set<pair<int, int>> vis;
        int all = (1 << n) - 1;
            
        for(int i = 0; i < n; i++) {
            int maskValue = (1 << i);
            tuple thisNode(i, maskValue, 1);
            q.push(thisNode);
            vis.insert({i, maskValue});
        }
        
        while(!q.empty()) {
            tuple curr = q.front();
            q.pop();
            
            if(curr.mask == all) 
                return curr.cost - 1;
            
            for(auto &adj: graph[curr.node]) {
                int bothVisitedMask = curr.mask;
                
                bothVisitedMask = bothVisitedMask | (1 << adj); 
                tuple ThisNode(adj, bothVisitedMask, curr.cost + 1);
                
                if(vis.find({adj, bothVisitedMask}) == vis.end()) {
                    vis.insert({adj, bothVisitedMask});
                    q.push(ThisNode);
                }
            }
        }

        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
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

        cout << ob.shortestPathLength(graph) << endl;
    }

    return 0;
}

/* Sample Input:
2

4
3 1 2 3
1 0
1 0
1 0

5
1 1
3 0 2 4
3 1 3 4
1 2
2 1 2


Sample Output:
4
4

*/