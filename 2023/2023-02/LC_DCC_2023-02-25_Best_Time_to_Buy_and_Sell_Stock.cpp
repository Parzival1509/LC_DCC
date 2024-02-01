// LC DCC 2023/02/25
// 121. Best Time to Buy and Sell Stock
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, pro = 0;
        for(int i=0; i<prices.size(); i++)
            if(mn > prices[i]) mn = prices[i];
            else pro = max(pro, prices[i]-mn);
        
        return pro;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        vector<int> prices(n);
        for(int i=0; i<n; i++)
            cin>>prices[i];
        cout<<ob.maxProfit(prices)<<endl;
    }
    return 0;
}

/* Sample Input:
2
6
7 1 5 3 6 4
5
7 6 4 3 1

Sample Output:
5
0

*/