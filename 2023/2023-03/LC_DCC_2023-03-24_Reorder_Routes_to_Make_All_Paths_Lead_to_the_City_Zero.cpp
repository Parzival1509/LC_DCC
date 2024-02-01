// LC DCC 2023/03/24
// 1466. Reorder Routes to Make All Paths Lead to the City Zero
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    void dfs(int node, int& ans, vector<vector<pair<int, bool>>>& destinations, vector<bool>& done) {
        done[node] = 1;
        for(auto& pr: destinations[node]) {
            int v = pr.first;
            bool dis = pr.second;
            if(done[v] == 0) {
                if(dis == 0) ans++;
                dfs(v, ans, destinations, done);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> destinations(n);
        for(auto city: connections) {
            destinations[city[1]].push_back({city[0], 1});
            destinations[city[0]].push_back({city[1], 0});
            //whether the city[1] is the destination of city[0]
        }
        vector<bool> done(n, 0);
        int ans = 0;
        dfs(0, ans, destinations, done);
        return ans;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        vector<vector<int>> connections;
        for(int i=0; i<n-1; i++) {
            vector<int> tmp(2);
            cin>>tmp[0]>>tmp[1];
            connections.push_back(tmp);
        }
        cout<<ob.minReorder(n, connections)<<endl;
    }
    return 0;
}

/* Sample Input:
3
6
0 1
1 3
2 3
4 0
4 5
5
1 0
1 2
3 2
3 4
3
1 0
2 0

Sample Output:
3
2
0

*/