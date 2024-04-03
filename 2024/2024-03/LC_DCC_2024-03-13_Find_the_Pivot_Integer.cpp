// LC DCC 2024/03/13
// 2485. Find the Pivot Integer
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        double a = sqrt(n * (n + 1) / 2);
        return (a - ceil(a) == 0)? (int)a: -1;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.pivotInteger(n) << endl;
    }

    return 0;
}

/* Sample Input
3
1
4
8

Sample Output
1
-1
6

*/