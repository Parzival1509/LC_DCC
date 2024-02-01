// LC DCC 2023/01/31
// 1626. Best Team With No Conflicts
// Medium

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Basic Idea is Max Subsequence Sum
class Solution {
public:
    int findMaxScore(vector<pair<int, int>>& tmp, int n) {
        int ans = 0;
        vector<int> dp(n);
        for(int i=0; i<n; i++) {
            dp[i] = tmp[i].second;
            ans = max(ans, dp[i]);
        }

        for(int i=0; i<n; i++) {
            for(int j=i-1; j>=0; j--)
                if(tmp[i].second >= tmp[j].second)
                    dp[i] = max(dp[i], tmp[i].second + dp[j]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int, int>> tmp(n);
        for(int i=0; i<n; i++)
            tmp[i] = {ages[i], scores[i]};
        sort(tmp.begin(), tmp.end());
        return findMaxScore(tmp, n);
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> scores(n), ages(n);
        for(int i=0; i<n; i++)
            cin>>scores[i];
        for(int i=0; i<n; i++)
            cin>>ages[i];
        cout<<ob.bestTeamScore(scores, ages)<<endl;
    }
    return 0;
}

/* Sample Input:
3
5
1 3 5 10 15
1 2 3 4 5
4
4 5 6 5
2 1 2 1
4
1 2 3 5
8 9 10 1

Sample Output:
34
16
6

*/