// LC DCC 2023/12/20
// 2706. Buy Two Chocolates
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int price = prices[0] + prices[1];

        return (price <= money)? (money - price): money;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, money;
        cin >> n >> money;
        vector<int> prices(n, 0);
        for(int &i: prices)
            cin >> i;
        cout << ob.buyChoco(prices, money) << endl;
    }

    return 0;
}

/* Sample Input:
2
3 3
1 2 2
3 3
3 2 3

Sample Output:
0
3

*/