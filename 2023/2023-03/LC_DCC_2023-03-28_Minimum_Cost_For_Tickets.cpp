// LC DCC 2023/03/28
// 983. Minimum Cost For Tickets
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int ndays = days[n-1];
        vector<int> dp(ndays+1);
        for (int i=1; i<=ndays; i++) {
            // If travel day, try all these types of passes and choose the min cost
            if (find(days.begin(), days.end(), i) != days.end()) {
                int a = ((i-1) >= 0)? dp[i-1]: 0;
                int b = ((i-7) >= 0)? dp[i-7]: 0;
                int c = ((i-30) >= 0)? dp[i-30]: 0; 
                dp[i] = min(min(a + costs[0], b+costs[1]), c+costs[2]); 
            }
            // If not a travel day, copy the previous day
            else dp[i] = dp[i-1];
        }
        return dp[ndays];
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        vector<int> days(n);
        for(int i=0; i<n; i++)
            cin>>days[i];
        vector<int> costs(3);
        cin>>costs[0]>>costs[1]>>costs[2];
        cout<<ob.mincostTickets(days, costs)<<endl;
    }
    return 0;
}

/* Sample Input:
2
6
1 4 6 7 8 20
2 7 15
12
1 2 3 4 5 6 7 8 9 10 30 31
2 7 15

Sample Output:
11
17

*/