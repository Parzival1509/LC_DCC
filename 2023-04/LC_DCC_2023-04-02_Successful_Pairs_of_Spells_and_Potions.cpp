// LC DCC 2023/04/02
// 2300. Successful Pairs of Spells and Potions
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, ll success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            ll complement = (ceil)(1.0*success/spells[i]);
            ans[i] = m - (lower_bound(potions.begin(), potions.end(), complement) - potions.begin());
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, m;
        ll success;
        cin>>n>>m>>success;
        vector<int> spells(n), potions(m);
        for(auto &spell: spells)
            cin>>spell;
        for(auto &potion: potions)
            cin>>potion;
        vector<int> ans = ob.successfulPairs(spells, potions, success);
        for(auto el: ans)
            cout<<el<<' ';
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
3 5 7
5 1 3
1 2 3 4 5
3 3 16
3 1 2
8 5 8

Sample Output:
4 0 3
2 0 2

*/