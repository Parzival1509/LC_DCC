// LC DCC 2023/08/26
// 646. Maximum Length of Pair Chain
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    
    int solve(int i, int prev, vector<vector<int>>& pairs, int n, vector<vector<int>>& dp) {
        if(i == n) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int pick = -1e9;
        if(prev == -1 || pairs[prev][1] < pairs[i][0])
            pick = 1 + solve(i + 1, i, pairs, n, dp);
        int not_pick = solve(i + 1, prev, pairs, n, dp);

        return dp[i][prev + 1] = max(pick, not_pick);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        // Approach 1: Greedy, T.C. = O(NlogN), S.C. = O(1)
        sort(pairs.begin(), pairs.end(), cmp);
        int prev = 0, res = 1;
        for(int i = 1; i < pairs.size(); i++)
            if(pairs[prev][1] < pairs[i][0]) {
                prev = i;
                res++;
            }
        
        return res;

        // // Approach 2: DP, T.C. = O(N ^ 2), S.C. = O(N ^ 2)
        // int n = pairs.size();
        // sort(pairs.begin(), pairs.end());
        // vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        // return solve(0, -1, pairs, n, dp);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> pairs(n, vector<int> (2, 0));
        for(int i = 0; i < n; i++)
            cin >> pairs[i][0] >> pairs[i][1];
        cout << ob.findLongestChain(pairs) << endl;
    }

    return 0;
}

/* Sample Input:
2

3
1 2
2 3
3 4

3
1 2
7 8
4 5

Sample Output:
2
3

*/