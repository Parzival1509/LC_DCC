// LC DCC 2022/12/21
// 886. Possible Bipartition
// Medium

#include <bits/stdc++.h>
using namespace std;

// Baijnath's Sol
class Solution {
public:
    bool possibleBipartition(int V, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(V+1);
        for(int i=0; i<dislikes.size(); i++) {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> col(V+1, -1);
        queue<pair<int, int>> q;
        for(int i = 1; i <= V; i++) {
            if(col[i] == -1) {
                q.push({ i, 0 });
                col[i] = 0;
                while(!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    int v = p.first;
                    int c = p.second;
                    for(int j: adj[v]) {
                        if (col[j] == c) return 0;
                        if (col[j] == -1) {
                            col[j] = !c;
                            q.push({j, col[j] });
                        }
                    }
                }
            }
        }
        return 1;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> dislikes(m, vector<int> (2, 0));
        for(int i=0; i<m; i++)
            cin>>dislikes[i][0]>>dislikes[i][1];
        cout<<ob.possibleBipartition(n, dislikes)<<endl;
    }
}

/* Sample Input
3
3
3
1 2
1 3
2 3
4
3
1 2
1 3
2 4
5
5
1 2
2 3
3 4
4 5
1 5

Sample Output
0
1
0

*/