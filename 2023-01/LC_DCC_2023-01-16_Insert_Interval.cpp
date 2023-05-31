// LC DCC 2023/01/16
// 57. Insert Interval
// Medium

#include <bits/stdc++.h>
using namespace std;

// Baijnath's Sol
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> result;
        
        while(i < intervals.size()) {
            if(intervals[i][1] < newInterval[0])
                result.push_back(intervals[i]);
            else if (intervals[i][0] > newInterval[1])
                break;
            else {
                //Overlap : merge them
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        
        result.push_back(newInterval);
        while(i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n;
        cin>>n;
        vector<vector<int>> intervals(n, vector<int> (2, 0)), ans;
        for(int i=0; i<n; i++)
            cin>>intervals[i][0]>>intervals[i][1];
        vector<int> newInterval(2);
        cin>>newInterval[0]>>newInterval[1];
        ans = ob.insert(intervals, newInterval);
        for(auto el: ans) {
            for(auto ell: el)
                cout<<ell<<' ';
            cout<<endl;
        }
        cout<<endl;
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