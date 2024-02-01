// LC DCC 2023/12/21
// 1637. Widest Vertical Area Between Two Points Containing No Points
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xSorted;
        for(auto& point: points)
            xSorted.push_back(point[0]);

        sort(xSorted.begin(), xSorted.end());

        int maxWidth = 0;
        for(int i = 0; i < xSorted.size() - 1; i++)
            maxWidth = max(maxWidth, xSorted[i + 1] - xSorted[i]);

        return maxWidth;        
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
        cout << ob.maxWidthOfVerticalArea(points) << endl;
    }

    return 0;
}

/* Sample Input:
2
4
8 7
9 9
7 4
9 7
6
3 1
9 0
1 0
1 4
5 3
8 8

Sample Output:
1
3

*/