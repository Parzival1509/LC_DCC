// LC DCC 2023/05/19
// 785. Is Graph Bipartite?
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool helper(int depth, int k, vector<short>& status, vector<vector<int>>& neighbors) {
        status[k] = depth;
        for(int i = 0; i < neighbors[k].size(); i++) {
            if(!status[neighbors[k][i]]) {
                if(!helper(-depth, neighbors[k][i], status, neighbors)) {
                    return false;
                }
            }
            else if(status[neighbors[k][i]] == depth) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& edges) {
        vector<short> status(edges.size(), 0);
        for(int k = 0; k < edges.size(); k++)
            if(!status[k] || status[k] == 1)
                if(!helper(1, k, status, edges))
                    return false;
        
        return true;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> edges;
        for(int i=0; i<n; i++) {
            int num;
            cin>>num;
            vector<int> tmp(num, 0);
            for(int &i: tmp)
                cin>>i;
            edges.push_back(tmp);
        }
        if(ob.isBipartite(edges)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
        
    }
    return 0;
}

/* Sample Input:
2

4
3 1 2 3
2 0 2
3 0 1 3
2 0 2

4
2 1 3
2 0 2
2 1 3
2 0 2

Sample Output:
false 
true 

*/