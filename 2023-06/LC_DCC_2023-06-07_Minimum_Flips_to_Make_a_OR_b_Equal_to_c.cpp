// LC DCC 2023/06/07
// 1318. Minimum Flips to Make a OR b Equal to c
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while(a || b || c) {
            if((c & 1) == 1)
                flips += ((a & 1) == 0) && ((b & 1) == 0);
            else
                flips += (a & 1) + (b & 1);
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << ob.minFlips(a, b, c) << endl;
    }
    return 0;
}

/* Sample Input:
3
2 6 5
4 2 7
1 2 3

Sample Output:
3
1
0

*/