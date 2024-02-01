// LC DCC 2023/04/27
// 319. Bulb Switcher
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int bulbSwitch(int n) {
        int cnt = 0;
        for(int i = 1; i*i <= n; i++) cnt++;
        return cnt;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        cout<<ob.bulbSwitch(n)<<endl;
    }
    return 0;
}

/* Sample Input:
3
0
1
3

Sample Output:
0
1
1

*/