// LC DCC 2022/12/20
// 841. Keys and Rooms
// Medium

#include <bits/stdc++.h>
using namespace std;

// Baijnath's Sol + some modification
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        unordered_set<int> st;
        queue<int> q;
        q.push(0);
        st.insert(0);
        while(!q.empty()) {
            int room=q.front();
            q.pop();
            for(auto key: rooms[room])
               if(st.count(key)==0) {
                   st.insert(key);
                   q.push(key);
               }
        }
        return st.size()==rooms.size();
    }
};

// // Baijnath's Sol
// class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int n=rooms.size();
//         vector<bool> vis(n, false);
//         queue<int> q;
//         q.push(0);
//         vis[0]=true;
//         while(!q.empty()) {
//             int room=q.front();
//             q.pop();
//             for(auto key: rooms[room])
//                if(!vis[key]) {
//                    vis[key]=true;
//                    q.push(key);
//                }
//         }
//         for(auto x: vis)
//             if(!x) return x;
//         return true;
//     }
// };

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<vector<int>> rooms(n);
        for(int i=0; i<n; i++)
            cin>>edges[i][0]>>edges[i][1];
        
    }
}

/* Sample Input
2
[[1],[2],[3],[]]
[[1,3],[3,0,1],[2],[0]]

Sample Output
1 1 0 
1 1 1 0 
1 1 4 2 1 1 0 0 

*/