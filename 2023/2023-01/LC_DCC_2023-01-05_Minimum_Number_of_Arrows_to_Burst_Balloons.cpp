// LC DCC 2023/01/05
// 452. Minimum Number of Arrows to Burst Balloons
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int arrows = 1, last = points[0][1];
        for(int i=1; i<points.size(); i++)
            if(points[i][0] > last) {
                arrows++;
                last = points[i][1];
            }
        return arrows;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<vector<int>> points(n, vector<int> (2, 0));
        for(int i=0; i<n; i++)
            cin>>points[i][0]>>points[i][1];
        cout<<ob.findMinArrowShots(points)<<endl;
    }
    return 0;
}

/* Sample Input
3
4
10 16
2 8
1 6
7 12
4
1 2
3 4
5 6
7 8
4
1 2
2 3
3 4
4 5

Sample Output
2
4
2

*/