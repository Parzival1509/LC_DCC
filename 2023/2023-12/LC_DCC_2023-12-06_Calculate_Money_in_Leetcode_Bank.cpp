// LC DCC 2023/12/06
// 1716. Calculate Money in Leetcode Bank
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int rem = n % 7;
        int total = 28 * weeks + 7 * ((weeks - 1) * weeks / 2);
        total += (rem * (rem + 1) / 2) + weeks * rem;

        return total;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.totalMoney(n) << endl;
    }

    return 0;
}

/* Sample Input:
4
4
10
20
26

Sample Output:
10
37
96
135

*/