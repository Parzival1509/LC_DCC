// LC DCC 2023/02/22
// 1011. Capacity To Ship Packages Within D Days
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool checkCapacity(vector<int>& weights, int days, int cap, int n) {
        int ct = 0, sum = 0;

        // Counting the Number of Days
        for(int i=0; i<n; i++) {
            sum += weights[i];
            if(sum > cap) {
                ct++;
                sum = weights[i];
            }
        }
        if(sum > 0) ct++;
        return ct <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);

        // Finding out the Minimum Capacity
        while(hi-lo > 1) {
            int mid = (lo + hi) / 2;
            if(checkCapacity(weights, days, mid, n)) hi = mid;
            else lo = mid + 1;
        }

        if(checkCapacity(weights, days, lo, n)) return lo;
        return hi;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n, days;
        cin>>n>>days;
        vector<int> weights(n);
        for(int i=0; i<n; i++)
            cin>>weights[i];
        cout<<ob.shipWithinDays(weights, days)<<endl;
    }
    return 0;
}

/* Sample Input:
3
10 5
1 2 3 4 5 6 7 8 9 10
6 3
3 2 2 4 1 4
5 4
1 2 3 1 1

Sample Output:
15
6
3

*/