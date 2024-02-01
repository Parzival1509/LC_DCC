// LC DCC 2023/06/02
// 2101. Detonate the Maximum Bombs
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // // Approach 1: Using bitset
    // int dfs(int i, vector<vector<int>> &al, bitset<100> &detonated) {
    //     if(!detonated[i]) {
    //         detonated[i] = true;
    //         for(int j: al[i])
    //             dfs(j, al, detonated);
    //     }
    //     return detonated.count();
    // }

    // int maximumDetonation(vector<vector<int>>& bs) {
    //     int res = 0, sz = bs.size();
    //     vector<vector<int>> al(bs.size());
    //     for(int i = 0; i < sz; ++i) {
    //         ll x = bs[i][0];
    //         ll y = bs[i][1];
    //         ll r2 = (ll )bs[i][2] * bs[i][2];
    //         for(int j = 0; j < bs.size(); ++j)
    //             if((x - bs[j][0]) * (x - bs[j][0]) + (y - bs[j][1]) * (y - bs[j][1]) <= r2)
    //                 al[i].push_back(j);
    //     }
    //     for(int i = 0; i < sz && res < sz; ++i)
    //         res = max(dfs(i, al, bitset<100>() = {}), res);

    //     return res;
    // }

    // Approach 2:
    void dfs(vector<vector<int>> &gr, vector<bool> &visited, int &c, int &i) {
        visited[i] = true;
        c++;
        for(int j = 0; j < gr[i].size(); j++)
            if(!visited[gr[i][j]])
                dfs(gr, visited, c, gr[i][j]);
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int> > gr(n);
        for(int i = 0; i < n; i++) {
            ll x1 = bombs[i][0];
            ll y1 = bombs[i][1];
            ll r1 = bombs[i][2];
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    ll x = abs(x1 - bombs[j][0]);
                    ll y = abs(y1 - bombs[j][1]);
                    if(x*x + y*y <= r1*r1)
                        gr[i].push_back(j);
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int c = 0;
            vector<bool> visited(n, false);
            dfs(gr, visited, c, i);
            ans = max(ans, c);
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
        cin >> n;
        vector<vector<int>> bombs(n, vector<int> (3, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 3; j++)
                cin>>bombs[i][j];
        cout<<ob.maximumDetonation(bombs)<<endl;
    }
    return 0;
}

/* Sample Input:
3
2
2 1 3
6 1 4
2
1 1 5
10 10 5
5
1 2 3
2 3 1
3 4 2
4 5 3
5 6 4

Sample Output:
2
1
5

*/