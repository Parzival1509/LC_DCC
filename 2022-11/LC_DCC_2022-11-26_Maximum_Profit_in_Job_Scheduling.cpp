// LC DCC 2022/11/26
// 1235. Maximum Profit in Job Scheduling
// Hard

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();
bool cmp(pair<string, int> A, pair<string, int> B){
    if(A.first != B.first)
        return A.second < B.second;
    return B.first > A.first;
}

// Baijnath's Sol
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size(), ans=0;
        vector<vector<int>> v;
        for(int i=0; i<n; i++)
            v.push_back({endTime[i], startTime[i], profit[i]});
        sort(v.begin(), v.end());
        vector<int> dp(n);
        for(int i=0; i<n; i++) {
            dp[i]=v[i][2];
            if(i==0) {
                ans=max(ans, dp[i]);
                continue;
            }
            dp[i]=max(dp[i], dp[i-1]);
            int curr=v[i][1];
            for(int j=i-1; j>=0; j--)
                if(v[j][0]<=curr) {
                    dp[i]=max(dp[i], dp[j]+v[i][2]);
                    break;
                }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> st(n), et(n), pr(n);
        for(int i=0; i<n; i++)
            cin>>st[i];
        for(int i=0; i<n; i++)
            cin>>et[i];
        for(int i=0; i<n; i++)
            cin>>pr[i];
        cout<<ob.jobScheduling(st, et, pr)<<endl;
    }
    return 0;
}

/* Sample Input
2
4
1 2 3 3
3 4 5 6
50 10 40 70
5
1 2 3 4 6
3 5 10 6 9
20 20 100 70 60

Sample Output
120
150

*/