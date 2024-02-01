// LC DCC 2023/01/08
// 149. Max Points on a Line
// Hard

#include <bits/stdc++.h>
using namespace std;

// Good T.C.
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        int maxPoints = 0;
        for(int i=0; i<n; i++) {
            unordered_map<double, int> m;
            for(int j=i+1; j<n; j++) {
                double x1 = points[i][0];
                double y1 = points[i][1];
                double x2 = points[j][0];
                double y2 = points[j][1];
                double slope;
                double dx = x2-x1;
                if(dx == 0) slope=INT_MAX;
                else slope=((y2-y1)/dx);
                m[slope]++;
                maxPoints = max(maxPoints, m[slope]+1);
            }
        }
        return maxPoints;
    }
};

// // YT
// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         int ans = 0;

//         for(int i=0; i<points.size(); i++) {
//             unordered_map<double, int> mp;
//             int duplicate = 0;
//             double slope = 0.0;
//             for(int j=0; j<points.size(); j++) {
//                 int x1 = points[i][0];
//                 int x2 = points[j][0];
//                 int y1 = points[i][1];
//                 int y2 = points[j][1];
//                 int dx = x2-x1;
//                 int dy = y2-y1;
//                 if(dx==0 && dy==0) {
//                     duplicate++;
//                     continue;
//                 }
//                 if(dx != 0)
//                     slope = dy*1.0/dx;
//                 else
//                     slope = INT_MAX;
//                 mp[slope]++;
//             }
//             if(mp.size() == 0)
//                 ans = duplicate;
//             else
//                 for(auto slope: mp)
//                     ans = max(ans, slope.second+duplicate);
//         }
//         return ans;
//     }
// };

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
        cout<<ob.maxPoints(points)<<endl;
    }
    return 0;
}

/* Sample Input
2
3
1 1
2 2
3 3
6
1 1
3 2
5 3
4 1
2 3
1 4

Sample Output
3
4

*/