// LC DCC 2023/07/29
// 808. Soup Servings
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    double help(int a, int b, vector<vector<double>> &dp) {
        if(a <= 0 && b <= 0) return 0.5;
        if(b <= 0) return 0;
        if(a <= 0) return 1;

        if(dp[a][b] != -1) return dp[a][b];

        double ans = 0;
        // ans += help(a - 100, b, dp); 
        // ans += help(a - 75, b - 25, dp); 
        // ans += help(a - 50, b - 50, dp); 
        // ans += help(a - 25, b - 75, dp); 

        ans = help(a - 4, b, dp) + help(a - 3, b - 1, dp) + help(a - 2, b - 2, dp) + help(a - 1, b - 3, dp);
        return dp[a][b] = ans * 0.25;
    }

    double soupServings(int n) {
        if(n > 4800) return 1;
        
        // vector<vector<double>> dp(n + 1, vector<double> (n + 1, -1));
        // return help(n, n, dp);

        vector<vector<double>> dp(200, vector<double> (200, -1));
        return help((n + 24) / 25, (n + 24) / 25, dp);
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n;
        cin >> n;
        cout << ob.soupServings(n) << endl;
    }
    
    return 0;
}

/* Sample Input:
3
50 100 800

Sample Output:
0.625
0.71875
0.961618

*/