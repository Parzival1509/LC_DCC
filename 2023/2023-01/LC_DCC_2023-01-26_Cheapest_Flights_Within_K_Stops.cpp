// LC DCC 2023/01/26
// 787. Cheapest Flights Within K Stops
// Medium

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int st, int en, int k) {
        vector<int> price(n, 1e9);
        vector<vector<pair<int, int>>> adj(n);
        queue<pair<int, pair<int, int>>> q;

        for(vector<int>& v: edges) 
            adj[v[0]].push_back({v[1], v[2]});
        q.push({st, {0, 0}});
        price[st] = 0;

        while(!q.empty()) {
            int cur = q.front().first;
            int curprice = q.front().second.first;
            int moves = q.front().second.second;
            q.pop();
            if(moves > k)
                continue;
            for(pair<int, int>& p: adj[cur]) {
                if(price[p.first] <= curprice + p.second)
                    continue;
                q.push({p.first, {curprice + p.second, moves + 1}});
                price[p.first] = curprice + p.second;
            }
        }
        return price[en] == 1e9? -1: price[en];
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n, k, src, dst, m;
        cin>>n>>src>>dst>>k>>m;
        vector<vector<int>> flights(m, vector<int> (3, 0));
        for(int i=0; i<m; i++)
            cin>>flights[i][0]>>flights[i][1]>>flights[i][2];
        cout<<ob.findCheapestPrice(n, flights, src, dst, k)<<endl;
    }
    return 0;
}

/* Sample Input
3

4 0 3 1 5
0 1 100
1 2 100
2 0 100
1 3 600
2 3 200

3 0 2 1 3
0 1 100
1 2 100
0 2 500

3 0 2 0 3
0 1 100
1 2 100
0 2 500

Sample Output
700
200
500

*/