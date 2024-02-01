// LC DCC 2022/12/23
// 309. Best Time to Buy and Sell Stock with Cooldown
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Good T.C.    O(N)
    int maxProfit(vector<int>& prices) {
        int sold = INT_MIN, held = INT_MIN, reset = 0;
        for(int price: prices) {
          int preSold = sold;
          sold = held + price;
          held = max(held, reset - price);
          reset = max(reset, preSold);
        }
        return max(sold, reset);
    }

    // // Baijnath's Sol
    // int helper(vector<int> prices, int ind, int buy, int n, vector<vector<int>> &dp) {
    //     if(ind>=n) return 0; //base case
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     int profit;
    //     if(buy==0)  // We can buy the stock
    //         profit = max(0+helper(prices, ind+1, 0, n, dp), -prices[ind]+helper(prices, ind+1, 1, n, dp));
    //     if(buy==1)  // We can sell the stock
    //         profit = max(0+helper(prices, ind+1, 1, n, dp), prices[ind]+helper(prices, ind+2, 0, n, dp));
    //     return dp[ind][buy] = profit;
    // }

    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2, -1));
    //     int ans = helper(prices, 0, 0, n, dp);
    //     return ans; 
    // }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<int> prices(n);
        for(int i=0; i<n; i++)
            cin>>prices[i];
        cout<<ob.maxProfit(prices)<<endl;
    }
}

/* Sample Input
2
1
1
5
1 2 3 0 2

Sample Output
0 
3

*/