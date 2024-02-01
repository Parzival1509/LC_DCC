// LC DCC 2022/12/13
// 931. Minimum Falling Path Sum
// Medium

#include <bits/stdc++.h>
using namespace std;

// Adi's Sol
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> prev(m, 0);
        for(int j=0; j<m; ++j)
            prev[j] = matrix[0][j];

        for(int i=1; i<n; ++i){
            vector<int> curr(m, 0);
            for(int j=0; j<m; ++j){
                int up = matrix[i][j] + prev[j];
                int left = 1e9;
                int right = 1e9;
                if(j > 0)
                    left = matrix[i][j] + prev[j-1];
                if(j < m-1)
                    right = matrix[i][j] + prev[j+1];
                curr[j] = min(up, min(left,right));
            }
            prev = curr;
        }
        
        int mini = 1e9;
        for(int j=0; j<m; ++j)
            mini = min(mini, prev[j]);
        return mini;
    }
};

// // Using DP
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int dp[n+2][n+2];
//         memset(dp,0,sizeof(dp));
//         for(int i=0; i<=n+1; i++)   dp[0][i]=0;
//         for(int i=1; i<=n+1; i++)   dp[i][0]=INT_MAX;
//         for(int i=1; i<=n+1; i++)   dp[i][n+1]=INT_MAX;
//         for(int i=1; i<=n; i++)
//             for(int j=1; j<=n; j++)
//                 dp[i][j] = matrix[i-1][j-1] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
        
//         int ans=INT_MAX;
//         for(int i=1; i<=n; i++)
//             ans=min(ans, dp[n][i]);
//         return ans;
//     }
// };

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> matrix(n, vector<int> (m, 0));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>matrix[i][j];
        cout<<ob.minFallingPathSum(matrix)<<endl;
    }
}

/* Sample Input
2
2 2
-19 57
-40 -5
3 3
2 1 3
6 5 4
7 8 9

Sample Output
-59
13

*/