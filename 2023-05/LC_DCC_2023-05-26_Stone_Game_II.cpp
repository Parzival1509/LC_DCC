// LC DCC 2023/05/26
// 1140. Stone Game II
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int dp[101][101];

    int helper(int i, int m, vector<int>& piles) {
        if(i >= piles.size()) return 0;
        if(dp[i][m] != -1) return dp[i][m];

        int total = 0, ans = INT_MIN;
        for(int j = 0; j < 2 * m; j++) {
            if(i+j < piles.size())
                total += piles[i+j];
            ans = max(ans, total - helper(i+j+1, max(m, j+1), piles));  
        }
        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof dp);
        int sum = 0;
        for(auto x: piles)
            sum += x;
        int diff = helper(0, 1, piles);
        
        return (sum + diff)/2;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<int> piles(n, 0);
        for(int &i: piles)
            cin>>i;

        cout<<ob.stoneGameII(piles)<<endl;
    }
    return 0;
}

/* Sample Input:
2
5
2 7 9 4 4
6
1 2 3 4 5 100

Sample Output:
10
104

*/