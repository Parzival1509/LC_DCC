// LC DCC 2023/01/06
// 1833. Maximum Ice Cream Bars
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans=0;
        for(auto el: costs) {
            coins -= el;
            if(coins >= 0) ans++;
            else break;
        }
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n, coins;
        cin>>n>>coins;
        vector<int> costs(n);
        for(int i=0; i<n; i++)
            cin>>costs[i];
        cout<<ob.maxIceCream(costs, coins)<<endl;
    }
    return 0;
}

/* Sample Input
3
5 7
1 3 2 4 1
6 5
10 6 8 7 7 8
6 20
1 6 3 1 2 5

Sample Output
4
0
6

*/