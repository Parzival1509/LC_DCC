// LC DCC 2023/12/05
// 1688. Count of Matches in Tournament
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int numberOfMatches(int n) {
        if(n == 1) return 0;

        if(n & 1) return ((n - 1) / 2) + numberOfMatches(1 + ((n - 1) / 2));
        return (n / 2) + numberOfMatches(n / 2);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.numberOfMatches(n) << endl;
    }

    return 0;
}

/* Sample Input:
2
7
14

Sample Output:
6
13

*/