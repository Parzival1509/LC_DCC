// LC DCC 2023/06/22
// 714. Best Time to Buy and Sell Stock with Transaction Fee
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN, sell = 0;
        for(int price: prices) {
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
        }
        return sell;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n, fee;
        cin >> n >> fee;
        vector<int> prices(n, 0);
        for(int &i: prices)
            cin >> i;
        cout << ob.maxProfit(prices, fee) << endl;
    }
    return 0;
}

/* Sample Input:
2
6 2
1 3 2 8 4 9
6 3
1 3 7 5 10 3

Sample Output:
8
6

*/