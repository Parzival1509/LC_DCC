// LC DCC 2023/08/31
// 1326. Minimum Number of Taps to Open to Water a Garden
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
     int minTaps(int n, vector<int>& ranges) {
        // Approach 1:
        vector<int> arr(n + 1, 0);
        for(int i = 0; i < ranges.size(); ++i) {
            if(ranges[i] == 0) continue;
            int left = max(0, i - ranges[i]);
            arr[left] = max(arr[left], i + ranges[i]);
        }
        
        int end = 0, far_can_reach = 0, cnt = 0;
        for(int i = 0; i <= n; ++i) {
            if(i > end) {
                if(far_can_reach <= end) return -1;
                end = far_can_reach;
                ++cnt;
            }
            far_can_reach = max(far_can_reach, arr[i]);
        }
        
        return cnt + (end < n);

        // // Approach 2:
        // vector<int> dp(n + 1, n + 2);
        // dp[0] = 0;
        // for(int i = 0; i <= n; ++i)
        //     for(int j = max(i - ranges[i] + 1, 0); j <= min(i + ranges[i], n); ++j)
        //         dp[j] = min(dp[j], dp[max(0, i - ranges[i])] + 1);
        
        // return (dp[n] < n + 2)? dp[n]: -1;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ranges(n + 1, 0);
        for(int &i: ranges)
            cin >> i;
        cout << ob.minTaps(n, ranges) << endl;
    }

    return 0;
}

/* Sample Input:
2
5
3 4 1 1 0 0
3
0 0 0 0

Sample Output:
1
-1

*/