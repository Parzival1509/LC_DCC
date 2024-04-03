// LC DCC 2024/03/17
// 57. Insert Interval
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> result;

        while (i < intervals.size()) {
            if (intervals[i][1] < newInterval[0])
                result.push_back(intervals[i]);
            else if (intervals[i][0] > newInterval[1])
                break;
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }

        result.push_back(newInterval);
        while (i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, {0, 0});
        for(int i = 0; i < n; i++)
            cin >> intervals[i][0] >> intervals[i][1];
        vector<int> newInterval(2, 0);
        cin >> newInterval[0] >> newInterval[1];

        vector<vector<int>> ans = ob.insert(intervals, newInterval);
        for(auto i: ans)
            cout << i[0] << ' ' << i[1] << endl;
        cout << endl;
    }

    return 0;
}

/* Sample Input
2

2
1 3
6 9
2 5

5
1 2
3 5
6 7
8 10
12 16
4 8

Sample Output
1 5
6 9

1 2
3 10
12 16


*/