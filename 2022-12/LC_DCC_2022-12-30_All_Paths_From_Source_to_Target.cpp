// LC DCC 2022/12/30
// 797. All Paths From Source to Target
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<vector<int>> q;
        q.push({0});
        
        while(!q.empty()) {
            vector<int> path = q.front();
            q.pop();
            if(path.back() == graph.size()-1)
                ans.push_back(path);
            else
                for(int child: graph[path.back()]) {
                    path.push_back(child);
                    q.push(path);
                    path.pop_back();
                }
        }
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<vector<int>> graph;
        for(int i=0; i<n; i++) {
            int m;
            cin>>m;
            vector<int> tmp(m);
            for(int j=0; j<m; j++)
                cin>>tmp[j];
            graph.push_back(tmp);
        }
        vector<vector<int>> ans = ob.allPathsSourceTarget(graph);
        for(auto path: ans) {
            for(auto node: path)
                cout<<node<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}

/* Sample Input
2
4
2
1 2
1
3
1
3
0
5
3
4 3 1
3
3 2 4
1
3
1
4
0

Sample Output
0 1 3 
0 2 3 

0 4 
0 3 4 
0 1 4 
0 1 3 4 
0 1 2 3 4 


*/