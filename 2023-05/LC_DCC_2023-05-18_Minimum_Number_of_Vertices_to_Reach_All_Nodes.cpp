// LC DCC 2023/05/18
// 1557. Minimum Number of Vertices to Reach All Nodes
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans, indegree (n, 0);
        for(int i = 0; i < edges.size(); i++)
            indegree[edges[i][1]] += 1;
        for(int i = 0; i < indegree.size(); i++)
            if(indegree[i] == 0)
                ans.push_back(i);
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> edges(m, vector<int> (2, 0));
        for(int i=0; i<m; i++)
            cin>>edges[i][0]>>edges[i][1];
        vector<int> ans = ob.findSmallestSetOfVertices(n, edges);
        for(int i: ans)
            cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2

6 5
0 1
0 2
2 5
3 4
4 2

5 5
0 1
2 1
3 1
1 4
2 4

Sample Output:
0 3 
0 2 3 

*/