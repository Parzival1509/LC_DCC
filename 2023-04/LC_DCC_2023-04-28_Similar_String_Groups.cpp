// LC DCC 2023/04/28
// 839. Similar String Groups
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool similar(string &s, string &t) {
        int diff = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] != t[i])
                diff++;
        return diff <= 2;
    }

    void dfs(int node, vector<int> &vis, vector<vector<int>> &graph) {
        vis[node] = 1;
        for(auto &child: graph[node])
            if(!vis[child])
                dfs(child, vis, graph);
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size(), ans = 0;
        vector<vector<int>> graph(strs.size());
        for(int i = 1; i < n; i++)
            for(int j = 0; j < i; j++)
                if(similar(strs[i], strs[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }

        vector<int> vis(n);
        for(int i = 0; i < n; i++)
            if(!vis[i]) {
                dfs(i, vis, graph);
                ans++;
            }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<string> strs(n, "");
        for(auto &i: strs)
            cin>>i;
        cout<<ob.numSimilarGroups(strs)<<endl;
    }
    return 0;
}

/* Sample Input:
2
2
omv ovm
4
tars rats arts star

Sample Output:
1
2

*/