// LC DCC 2022/12/12
// 70. Climbing Stairs
// Easy

#include <bits/stdc++.h>
using namespace std;

// // Using DP
// class Solution {
// public:
//     int solve(vector<int> &dp, int n){
//         if(n == 1 || n == 2)
//             return n;
//         if(dp[n] != -1)
//             return dp[n];
//         return dp[n] = solve(dp, n-1) + solve(dp, n-2);
//     }
    
//     int climbStairs(int n){
//         vector<int> dp(n+1, -1);
//         return solve(dp, n);
//     }
// };

// Best T.C. Sol
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int firstStep = 1, secondStep = 2;
        for(int i = 2; i < n; ++i){
            int temp = firstStep;
            firstStep = secondStep;
            secondStep = firstStep + temp;
        }
        return secondStep;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        cout<<ob.climbStairs(n)<<endl;
    }
}

/* Sample Input
2
2 3

Sample Output
2
3

*/