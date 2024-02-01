// LC DCC 2023/05/20
// 399. Evaluate Division
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for(int i = 0; i < n; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            
            graph[a].push_back({b, val});
            graph[b].push_back({a, (double)1/val});
        }
        
        vector<double> result;
        for(auto query: queries) {
            unordered_set<string> visited;
            result.push_back(dfs(query[0], query[1], visited));
        }
        return result;
    }
    
    double dfs(string src, string dst, unordered_set<string> &visited) {
        if(graph.find(src) == graph.end()) return -1;
        if(src == dst) return 1;
        
        for(auto node: graph[src]) {
            if(visited.count(node.first)) continue;
            visited.insert(node.first);
            double res = dfs(node.first, dst, visited);
            if(res != -1) return res * node.second;
        }
        return -1;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<string>> equations(n, vector<string> (2, ""));
        for(int i=0; i<n; i++)
            cin>>equations[i][0]>>equations[i][1];
        vector<double> values(n, 0.0);
        for(auto &i: values)
            cin>>i;

        int q;
        cin>>q;
        vector<vector<string>> queries(q, vector<string> (2, ""));
        for(int i=0; i<q; i++)
            cin>>queries[i][0]>>queries[i][1];
        vector<double> ans = ob.calcEquation(equations, values, queries);
        for(auto el: ans)
            cout<<el<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
3

2
a b
b c
2.0 3.0
5
a c
b a
a e
a a
x x

3
a b
b c
bc cd
1.5 2.5 5.0
4
a c
c b
bc cd
cd bc

1
a b
0.5
4
a b
b a
a c
x y

Sample Output:
6 0.5 -1 1 -1 
6 0.333333 5 0.2 
2 0.5 6 -1 

*/