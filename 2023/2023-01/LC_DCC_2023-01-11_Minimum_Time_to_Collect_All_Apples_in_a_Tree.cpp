// LC DCC 2023/01/11
// 1443. Minimum Time to Collect All Apples in a Tree
// Medium

#include <bits/stdc++.h>
using namespace std;

// Baijnath's Sol
class Solution {
public:
    int helper(unordered_map<int, vector<int>> &adj, int curr, int parent, vector<bool>& hasApple) {
        int time = 0;
        for(int &child: adj[curr]) {
            if(child == parent) continue;
            int timeleft = helper(adj, child, curr, hasApple);
            if(timeleft || hasApple[child])
                time += 2+timeleft;
        }
        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return helper(adj, 0, -1, hasApple);
    }
};

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
1 null 2 3
null
1

Sample Output
1 2 3

1

*/