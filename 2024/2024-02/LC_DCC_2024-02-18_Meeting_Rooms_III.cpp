// LC DCC 2024/02/18
// 2402. Meeting Rooms III
// Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> ans(n, 0);
        vector<long long> times(n, 0);
        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0], end = meetings[i][1], minind = -1;
            bool flag = false;
            long long val = 1e18;
            for (int j = 0; j < n; j++) {
                if (times[j] < val)
                    val = times[j], minind = j;
                if (times[j] <= start) {
                    flag = true;
                    ans[j]++;
                    times[j] = end;
                    break;
                }
            }
            if (!flag) {
                ans[minind]++;
                times[minind] += (1ll * (end - start));
            }

        }
        
        int maxi = -1, id = -1;
        for (int i = 0; i < n; i++)
            if (ans[i] > maxi)
                maxi = ans[i], id = i;

        return id;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> meetings(m, {0, 0});
        for(int i = 0; i < m; i++)
            cin >> meetings[i][0] >> meetings[i][1];
        cout << ob.mostBooked(n, meetings) << endl;
    }

    return 0;
}

/* Sample Input
2

2 4
0 10
1 5
2 7
3 4

3 5
1 20
2 10
3 5
4 9
6 8

Sample Output
0
1

*/