// LC DCC 2023/06/20
// 1732. Find the Highest Altitude
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, alt = 0;
        for(int i = 0; i < gain.size(); i++) {
            alt += gain[i];
            ans = max(ans, alt);
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> gain(n, 0);
        for(int &i: gain)
            cin >> i;
        cout << ob.largestAltitude(gain) << endl;
    }
    return 0;
}

/* Sample Input:
2
5
-5 1 5 0 -7
7
-4 -3 -2 -1 4 3 2

Sample Output:
1
0

*/