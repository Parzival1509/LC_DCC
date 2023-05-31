// LC DCC 2023/01/28
// 352. Data Stream as Disjoint Intervals
// Hard

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class SummaryRanges {
    set<int> st;
public:
    SummaryRanges() {}
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(st.empty()) return {};

        vector<vector<int>> intervals;
        int left = -1, right = -1;

        for(auto value: st) {
            if(left < 0) left = right = value;
            else if(value == right+1) right = value;
            else {
                intervals.push_back({left, right});
                left = right = value;
            }
        }
        intervals.push_back({left, right});
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        
    }
    return 0;
}

/* Sample Input:
1
SummaryRanges addNum 1 getIntervals addNum 3 getIntervals addNum 7 getIntervals addNum 2 getIntervals addNum 6 getIntervals

Sample Output:


*/