// LC DCC 2023/07/19
// 435. Non-overlapping Intervals
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), prev = 0, count = 1;
        sort(intervals.begin(), intervals.end(), cmp);

        for(int i = 1; i < n; i++)
            if(intervals[i][0] >= intervals[prev][1]) {
                prev = i;
                count++;
            }

        return n - count;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int> (2, 0));
        for(int i = 0; i < n; i++)
            cin >> intervals[i][0] >> intervals[i][1];
        cout << ob.eraseOverlapIntervals(intervals) << endl;
    }
    
    return 0;
}

/* Sample Input:
3
4
1 2
2 3
3 4
1 3
3
1 2
1 2
1 2
2
1 2
2 3

Sample Output:
1
2
0

*/