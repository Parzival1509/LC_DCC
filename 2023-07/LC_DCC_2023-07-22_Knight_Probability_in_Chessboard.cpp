// LC DCC 2023/07/22
// 688. Knight Probability in Chessboard
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // // Approach 1: Using For Loop
    // bool isValid(int r, int c, int n) {
    //     return r >= 0 && r < n && c >= 0 && c < n;
    // }

    // double knightProbability(int n, int k, int row, int column) {
    //     vector<vector<double>> dp(n, vector<double> (n, 0));
    //     dp[row][column] = 1;
    //     vector<vector<int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    //     for (int move = 1; move <= k; move++) {
    //         vector<vector<double>> newDp(n, vector<double> (n, 0));

    //         for (int r = 0; r < n; r++)
    //             for (int c = 0; c < n; c++)
    //                 for (const auto& m : moves) {
    //                     int newR = r + m[0];
    //                     int newC = c + m[1];
    //                     if (isValid(newR, newC, n))
    //                         newDp[r][c] += dp[newR][newC] / 8.0;
    //                 }
            
    //         dp = newDp;
    //     }

    //     double probability = 0;
    //     for (int r = 0; r < n; r++)
    //         for (int c = 0; c < n; c++)
    //             probability += dp[r][c];

    //     return probability;
    // }

    // Approach 2: Using Recursion
    double help(int r, int c, int n, int k, vector<vector<vector<double>>> &dp) {
        if(r < 0 || c < 0 || r >= n || c >= n) return 0;
        if(k == 0) return 1;
        if(dp[r][c][k] != -1) return dp[r][c][k];

        int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
        double ans = 0;

        for(int i = 0; i < 8; i++)
            ans += help(r + dx[i], c + dy[i], n, k - 1, dp) / 8;
        return dp[r][c][k] = ans;
    }

    double knightProbability(int n, int k, int r, int c) {
        vector<vector<vector<double>>> dp(n + 1, vector<vector<double>> (n + 1, vector<double> (k + 1, -1)));
        return help(r, c, n, k, dp); 
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        cout << ob.knightProbability(n, k, r, c) << endl;
    }
    
    return 0;
}

/* Sample Input:
2
3 2 0 0
1 0 0 0

Sample Output:
0.0625
1

*/