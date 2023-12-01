// LC DCC 2023/11/29
// 191. Number of 1 Bits
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n != 0) {
            if(n & 1) ans++;
            n >>= 1;
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        uint32_t n;
        cin >> n;
        cout << ob.hammingWeight(n) << endl;
    }

    return 0;
}

/* Sample Input:
3
00000000000000000000000000001011
00000000000000000000000010000000
11111111111111111111111111111101

Sample Output:
3
3
1
31

*/