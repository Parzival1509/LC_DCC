// LC DCC 2023/12/03
// 1266. Minimum Time Visiting All Points
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int toTime(vector<int>& from, vector<int>& to) {
        int xDiff = abs(from[0] - to[0]);
        int yDiff = abs(from[1] - to[1]);
                
        return max(xDiff, yDiff);
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i = 1; i < points.size(); i++)
            time += toTime(points[i - 1], points[i]);

        return time;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> points(n, {0, 0});
        for(int i = 0; i < n; i++)
            cin >> points[i][0] >> points[i][1];
        cout << ob.minTimeToVisitAllPoints(points) << endl;
    }

    return 0;
}

/* Sample Input:
2
3
1 1
3 4
-1 0
2
3 2
-2 2

Sample Output:
7
5

*/