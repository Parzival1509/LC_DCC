// LC DCC 2022/12/15
// 1143. Longest Common Subsequence
// Medium

#include <bits/stdc++.h>
using namespace std;

// // Baijnath's Sol
// class Solution {
// public:
//     int lcshelper(string &x,string &y,int n,int m,vector<vector<int> > &t) {
//         if(n<0 || m<0) return 0;
//         if(t[n][m] != -1) return t[n][m];
//         if(x[n] == y[m]) return t[n][m] = 1+lcshelper(x, y, n-1, m-1, t);
//         return t[n][m] = max(lcshelper(x, y, n, m-1, t), lcshelper(x, y, n-1, m, t));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();
//         vector<vector<int>> t(n, vector<int>(m, -1));
//         return lcshelper(text1, text2, n-1, m-1, t);
//     }
// };

// Good T.C. Sol
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1= text1.size();
        int n2= text2.size();
        int dp[n1+1][n2+1];
        for(int i=0; i<=n1; i++)
            for(int j=0; j<=n2; j++)
                if(i==0 || j==0)
                    dp[i][j]=0;
        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++)
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1 + dp[i-1][j-1];
                else
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        return dp[n1][n2];
        
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        string text1, text2;
        cin>>text1>>text2;
        cout<<ob.longestCommonSubsequence(text1, text2)<<endl;
    }
}

/* Sample Input
3
abc abc
abc def
abcde ace

Sample Output
3
0
3

*/