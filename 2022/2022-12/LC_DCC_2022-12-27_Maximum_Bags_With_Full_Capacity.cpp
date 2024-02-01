// LC DCC 2022/12/27
// 2279. Maximum Bags With Full Capacity of Rocks
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        for(int i=0; i<n; i++)
            capacity[i] -= rocks[i];
        sort(capacity.begin(), capacity.end());
        int ans=0;
        for(int i=0; i<n; i++) {
            additionalRocks -= capacity[i];
            if(additionalRocks >= 0) ans++;
            else break;
        }
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n, additionalRocks;
        cin>>n>>additionalRocks;
        vector<int> capacity(n), rocks(n);
        for(int i=0; i<n; i++)
            cin>>capacity[i];
        for(int i=0; i<n; i++)
            cin>>rocks[i];
        cout<<ob.maximumBags(capacity, rocks, additionalRocks)<<endl;
    }
}

/* Sample Input
2
4 2
2 3 4 5
1 2 4 4
3 100
10 2 2
2 2 0

Sample Output
3
3

*/