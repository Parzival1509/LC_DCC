// LC DCC 2023/07/27
// 2141. Maximum Running Time of N Computers
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll maxRunTime(int n, vector<int>& b) {
        ll low = 1, high = accumulate(begin(b),end(b),0LL)/n;

        while(low < high) {
            ll mid = (high + low + 1)/2;
            ll time = 0;
            for(int t: b)
                time += min((ll)t, mid);

            if(mid*n <= time) low = mid;
            else high = mid-1;
        }

        return low;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        int n, b;
        cin >> n >> b;
        vector<int> batteries(b, 0);
        for(int &i: batteries)
            cin >> i;
        cout << ob.maxRunTime(n, batteries) << endl;
    }
    
    return 0;
}

/* Sample Input:
2
2 3
3 3 3
2 4
1 1 1 1

Sample Output:
4
2

*/