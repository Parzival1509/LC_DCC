// LC DCC 2023/11/30
// 1611. Minimum One Bit Operations to Make Integers Zero
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res;
        for(res = 0; n > 0; n &= n - 1)
            res = -(res + (n ^ (n - 1)));
        
        return abs(res);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.minimumOneBitOperations(n) << endl;
    }

    return 0;
}

/* Sample Input:
2
3
6

Sample Output:
2
4

*/