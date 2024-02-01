// LC DCC 2023/03/07
// 2187. Minimum Time to Complete Trips
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool check(vector<int>& time, int totalTrips, ll mid) {
        ll trips = 0;
        for(int i=0; i<time.size(); i++) {
            trips += mid/time[i];
            if(trips >= totalTrips) return true;
        }
        return trips >= totalTrips;
    }

    ll minimumTime(vector<int>& time, int totalTrips) {
        ll lo = 1, hi = 1e14;
        while(hi - lo > 0) {
            ll mid = (hi + lo) / 2;
            if(check(time, totalTrips, mid)) hi = mid;
            else lo = mid + 1;
        }
        if(check(time, totalTrips, lo)) return lo;
        return hi;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n, totalTrips;
        cin>>n>>totalTrips;
        vector<int> time(n);
        for(int i=0; i<n; i++)
            cin>>time[i];
        cout<<ob.minimumTime(time, totalTrips)<<endl;
    }
    return 0;
}

/* Sample Input:
3
3 5
1 2 3
1 1
2
1 10000000
10000

Sample Output:
3
2
100000000000

*/