// LC DCC 2023/07/15
// 1751. Maximum Number of Events That Can Be Attended II
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int help(vector<vector<int>>& events, int k, int i, vector<vector<int>>& dp) {
        if(i >= events.size()) return 0;

        if(dp[i][k] != -1) return dp[i][k];
        int ans = help(events, k, i + 1, dp);

        if(k) {
            // Approach 1: Without Binary Search
            int n = events.size();
            for(int j = i + 1; j < n; j++)
                if(events[j][0] > events[i][1]) {
                    n = j;
                    break;
                }
            
            // // Approach 2: With Binary Search
            // vector<int> temp = {events[i][1], INT_MAX, INT_MAX};
            // int n = upper_bound(events.begin(), events.end(), temp) - events.begin();

            ans = max(ans, events[i][2] + help(events, k - 1, n, dp));
        }

        return dp[i][k] = ans;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int> (k + 1, -1));
        return help(events, k, 0, dp);
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> events(n, vector<int> (3, 0));
        for(int i = 0; i < n; i++)
            cin >> events[i][0] >> events[i][1] >> events[i][2];

        cout << ob.maxValue(events, k) << endl;
    }
    
    return 0;
}

/* Sample Input:
3

3 2
1 2 4
3 4 3
2 3 1

3 2
1 2 4
3 4 3
2 3 10

4 3
1 1 1
2 2 2
3 3 3
4 4 4

Sample Output:
7
10
9

*/