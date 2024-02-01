// LC DCC 2023/03/29
// 1402. Reducing Dishes
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(), sat.end(), greater<int>());
        vector<int> sum = sat;
        for(int i=1; i<n; i++)
            sum[i] += sum[i-1];
        int mx = 0, cur = 0;
        for(int i=0; i<n; i++) {
            cur += sum[i];
            mx = max(cur, mx);
        }
        return mx;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        vector<int> sat(n);
        for(int i=0; i<n; i++)
            cin>>sat[i];
        cout<<ob.maxSatisfaction(sat)<<endl;
    }
    return 0;
}

/* Sample Input:
3
5
-1 -8 0 5 -9
3
4 3 2
3
-1 -4 -5

Sample Output:
14
20
0

*/