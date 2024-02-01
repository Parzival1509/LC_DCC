// LC DCC 2023/01/25
// 2359. Find Closest Node to Given Two Nodes
// Medium

#include<bits/stdc++.h>
using namespace std;

int start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

class Solution {
public:
    int closestMeetingNode(vector<int>& e, int node1, int node2) {
        int n = e.size();
        vector<int> vis1(n, -1), vis2(n, -1);
        if(node2 > node1) swap(node1, node2);
        
        while(vis1[node1]<0 || vis2[node2]<0) {
            if(vis1[node1] < 0) {
                vis1[node1] = 1;
                if(e[node1] != -1)
                    node1 = e[node1];
            }

            if(vis1[node2] < 0) {
                vis2[node2] = 1;
                if(e[node2] != -1)
                    node2 = e[node2];
            }
            if(vis2[node1]==1 || node1==node2 ) return node1;
            if(vis1[node2] == 1) return node2;
        }
        return -1;
    }

    // pair<int, int> fun(vector<int>&edges, int node1, int node2) {
    //     unordered_map<int, int> mp;
    //     int n = edges.size(), len=0;
    //     vector<int> visi1(n+2, 0);
    //     vector<int> visi2(n+2, 0);
    //     mp[node1] = 0;
        
    //     while(edges[node1]!=-1 && visi1[node1]!=1) {
    //         visi1[node1] = 1;  
    //         node1 = edges[node1];
    //         mp[node1] = len++;
    //     }
    //     pair<int, int> p1 = {INT_MAX, -1};
    //     if(mp.find(node2) != mp.end()) {
    //         p1 = {mp[node2], node2};
    //         return p1;
    //     }
    //     while(edges[node2]!=-1 && visi2[node2]!=1) {
    //         visi2[node2] = 1;
    //         node2 = edges[node2];
    //         if(mp.find(node2) != mp.end()) {
    //             p1 = {mp[node2], node2};
    //             return p1;
    //         }
    //     }
    //     return p1;
    // }

    // int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    //     pair<int, int> p1 = fun(edges, node1, node2);
    //     pair<int, int> p2 = fun(edges, node2, node1);
        
    //     if(p1.second!=-1 && p1.first<p2.first)
    //         return p1.second;
    //     else if( p2.second!=-1 && p2.first<p1.first)
    //         return p2.second;
    //     else if(p1.first == p2.first) {
    //         if(p1.second < p2.second)
    //             return p1.second;
    //         else
    //             return p2.second;
    //     }
    //     return -1;
    // }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n, node1, node2;
        cin>>n>>node1>>node2;
        vector<int> edges(n);
        for(int i=0; i<n; i++)
            cin>>edges[i];
        cout<<ob.closestMeetingNode(edges, node1, node2)<<endl;
    }
    return 0;
}

/* Sample Input
2
4 0 1
2 2 3 -1
3 0 2
1 2 -1

Sample Output
2
2

*/