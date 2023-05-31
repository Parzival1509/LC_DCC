// LC DCC 2023/03/25
// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int dfs(int key, vector<bool> &v, vector<vector<int>> &m) {
        int count = 1;
        v[key] = true;
        for(auto &child: m[key])
            if(!v[child])
                count += dfs(child, v, m);
        return count;
    }

    ll countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> m(n);
        vector<bool> v(n, false);
        vector<int> res;
        for(auto &i: edges) {
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
            
        }
    
        ll ans = 0 ;
        int tc = 0;
        for(int i=0; i<n; i++)
            if(!v[i]) {
                int c = 0;
                c = dfs(i, v, m);
                ans += (ll)c*tc;
                tc += c;
            }

        return ans;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n, ct;
        cin>>n>>ct;
        vector<vector<int>> edges;
        for(int i=0; i<ct; i++) {
            vector<int> tmp(2);
            cin>>tmp[0]>>tmp[1];
            edges.push_back(tmp);
            // cin>>connections[i][0]>>connections[i][1];
        }
        cout<<ob.countPairs(n, edges)<<endl;
    }
    return 0;
}

/* Sample Input:
2

3 3
0 1
0 2
1 2

7 5
0 2
0 5
2 4
1 6
5 4

Sample Output:
0
14

*/