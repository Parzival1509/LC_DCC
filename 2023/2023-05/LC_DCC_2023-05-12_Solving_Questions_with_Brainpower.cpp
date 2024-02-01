// LC DCC 2023/05/12
// 2140. Solving Questions With Brainpower
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n+1, 0);
        for(int i=n-1; i>=0; i--) {
            int point = questions[i][0];
            int jump = questions[i][1];

            int nextQuestion = min(n, i+jump+1);
            dp[i] = max(dp[i+1], point + dp[nextQuestion]);
        }
        return dp[0];
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> questions(n, vector<int> (2, 0));
        for(int i=0; i<n; i++)
            cin>>questions[i][0]>>questions[i][1];
        cout<<ob.mostPoints(questions)<<endl;
    }
    return 0;
}

/* Sample Input:
2
4
3 2
4 3
4 4
2 5
5
1 1
2 2
3 3
4 4
5 5

Sample Output:
5
7

*/