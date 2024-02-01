// LC DCC 2024/01/06
// 1235. Maximum Profit in Job Scheduling
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int solve(int i, vector<vector<int>>& job, vector<int>& startTime, int n, vector<int>& dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int index = lower_bound(startTime.begin(), startTime.end(), job[i][1]) - startTime.begin();
        int pick = job[i][2] + solve(index, job, startTime, n, dp);
        int notpick = solve(i + 1, job, startTime, n, dp);

        return dp[i] = max(pick, notpick);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> job;
        vector<int> dp(n, -1);

        for (int i = 0; i < n; i++)
            job.push_back({startTime[i], endTime[i], profit[i]});
        sort(job.begin(), job.end());
        sort(startTime.begin(), startTime.end());

        return solve(0, job, startTime, n, dp);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> startTime(n, 0), endTime(n, 0), profit(n, 0);
        for(int &i: startTime)
            cin >> i;
        for(int &i: endTime)
            cin >> i;
        for(int &i: profit)
            cin >> i;
        cout << ob.jobScheduling(startTime, endTime, profit) << endl;
    }

    return 0;
}

/* Sample Input:
3
4
1 2 3 3
3 4 5 6
50 10 40 70
5
1 2 3 4 6
3 5 10 6 9
20 20 100 70 60
3
1 1 1
2 3 4
5 6 4

Sample Output:
120
150
6

*/