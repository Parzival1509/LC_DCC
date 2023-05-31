// LC DCC 2023/03/08
// 875. Koko Eating Bananas
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool check(vector<int>& piles, int h, int time) {
        int ct = 0;
        for(int i=0; i<piles.size(); i++) {
            ct += ceil(1.0*piles[i]/time);
            if(ct > h) return false;
        }
        return ct <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while(hi-lo > 1) {
            int mid = (hi+lo) / 2;
            if(check(piles, h, mid)) hi = mid;
            else lo = mid + 1;
        }
        if(check(piles, h, lo)) return lo;
        return hi;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n, h;
        cin>>n>>h;
        vector<int> piles(n);
        for(int i=0; i<n; i++)
            cin>>piles[i];
        cout<<ob.minEatingSpeed(piles, h)<<endl;
    }
    return 0;
}

/* Sample Input:
3
4 8
3 6 7 11
5 5
30 11 23 4 20
5 6
30 11 23 4 20

Sample Output:
4
30
23

*/