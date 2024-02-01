// LC DCC 2023/04/09
// 1857. Largest Color Value in a Directed Graph
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), k = 26;
        vector<int> indegrees(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for (vector<int>& edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            indegrees[v]++;
        }

        unordered_set<int> zero_indegree;
        for (int i = 0; i < n; i++)
            if (indegrees[i] == 0)
                zero_indegree.insert(i);
        
        vector<vector<int>> counts(n, vector<int>(k, 0));
        for (int i = 0; i < n; i++)
            counts[i][colors[i] - 'a']++;

        int max_count = 0, visited = 0;
        while (!zero_indegree.empty()) {
            int u = *zero_indegree.begin();
            zero_indegree.erase(u);
            visited++;
            for (int v: graph[u]) {
                for (int i = 0; i < k; i++)
                    counts[v][i] = max(counts[v][i], counts[u][i] + (colors[v] - 'a' == i? 1: 0));

                indegrees[v]--;
                if (indegrees[v] == 0)
                    zero_indegree.insert(v);
            }
            max_count = max(max_count, *max_element(counts[u].begin(), counts[u].end()));
        }
        return visited == n? max_count: -1;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        string colors;
        cin>>colors;
        int n;
        cin>>n;
        vector<vector<int>> edges(n, vector<int> (2, 0));
        for(int i=0; i<n; i++) {
            cin>>edges[i][0]>>edges[i][1];
        }
        cout<<ob.largestPathValue(colors, edges)<<endl;
    }
    return 0;
}

/* Sample Input:
2
abaca
4
0 1
0 2
2 3
3 4
a
1
0 0

Sample Output:
3
-1

*/