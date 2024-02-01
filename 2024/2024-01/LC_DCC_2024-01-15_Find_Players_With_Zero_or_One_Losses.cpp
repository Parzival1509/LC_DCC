// LC DCC 2024/01/15
// 2225. Find Players With Zero or One Losses
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        for(auto& m: matches) {
            mp[m[1]]++;
            mp[m[0]] += 0;
        }
        
        vector<vector<int>> res(2);
        for(auto i: mp) {
            int p = i.first, l = i.second;

            if(l == 0) res[0].push_back(p);
            else if(l == 1) res[1].push_back(p);
        }
        
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        
        return res;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> matches(n, {0, 0});
        for(auto &i: matches)
            cin >> i[0] >> i[1];
        vector<vector<int>> ans = ob.findWinners(matches);
        for(auto i: ans) {
            for(int e: i)
                cout << e << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
10
1 3
2 3
3 6
5 6
5 7
4 5
4 8
4 9
10 4
10 9
4
2 3
1 3
5 4
6 4

Sample Output
1 2 10 
4 5 7 8 

1 2 5 6 



*/