// LC DCC 2023/04/29
// 1697. Checking Existence of Edge Length Limited Paths
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }

    bool isConnectedAndWithinLimit(int p, int q, int limit, vector<int>& parent, vector<int>& weight) {
        return find(p, limit, parent, weight) == find(q, limit, parent, weight);
    }

    int find(int x, int limit, vector<int>& parent, vector<int>& weight) {
        while(x != parent[x]) {
            if(weight[x] >= limit) break;
            x = parent[x];
        }
        return x;
    }

    void unionByRank(int x, int y, int limit, vector<int>& parent, vector<int>& rank, vector<int>& weight) {
        int x_ref = find(x, INT_MAX, parent, weight);
        int y_ref = find(y, INT_MAX, parent, weight);
        if(x_ref != y_ref) {
            if(rank[x_ref] < rank[y_ref]) {
                parent[x_ref] = y_ref;
                weight[x_ref] = limit;
            }
            else {
                parent[y_ref] = x_ref;
                weight[y_ref] = limit;
                if(rank[x_ref] == rank[y_ref]) rank[x_ref]++;
            }
        }
    }
    
    vector<bool> distanceLimitedPathsExist(int length, vector<vector<int>>& adjList, vector<vector<int>>& queries) {
        vector<int> parent(length), rank(length), weight(length);
        for(int i = 0; i < length; i++)
            parent[i] = i;

        sort(adjList.begin(), adjList.end(), cmp);
        for(vector<int>& edge: adjList)
            unionByRank(edge[0], edge[1], edge[2], parent, rank, weight);

        vector<bool> answer;
        for(vector<int>& query: queries)
            answer.push_back(isConnectedAndWithinLimit(query[0], query[1], query[2], parent, weight));

        return answer;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, e, q;
        cin>>n>>e;
        vector<vector<int>> edges, queries;
        vector<int> tmp(3, 0);
        for(int i=0; i<e; i++) {
            cin>>tmp[0]>>tmp[1]>>tmp[2];
            edges.push_back(tmp);
        }
        cin>>q;
        for(int i=0; i<q; i++) {
            cin>>tmp[0]>>tmp[1]>>tmp[2];
            queries.push_back(tmp);
        }

        vector<bool> ans = ob.distanceLimitedPathsExist(n, edges, queries);
        for(auto el: ans) {
            if(el) cout<<"true ";
            else cout<<"false ";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2

3
4
0 1 2
1 2 4
2 0 8
1 0 16
2
0 1 2
0 2 5

5
4
0 1 10
1 2 5
2 3 9
3 4 13
2
0 4 14
1 4 13

Sample Output:
false 
true 

true 
false 


*/