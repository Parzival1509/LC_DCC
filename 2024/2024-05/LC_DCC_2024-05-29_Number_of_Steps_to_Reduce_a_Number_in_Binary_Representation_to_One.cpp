// LC DCC 2024/05/29
// 1404. Number of Steps to Reduce a Number in Binary Representation to One
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int l = s.length() - 1, carry = 0, count = 0;
        while (l > 0) {
            if (s[l] - '0' + carry == 0) {
                carry = 0;
                count++;
            } else if (s[l] - '0' + carry == 2) {
                carry = 1;
                count++;
            } else {
                carry = 1;
                count += 2;
            }
            l--;
        }

        if (carry == 1)
            count++;

        return count;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        string s;
        cin >> s;
        cout << ob.numSteps(s) << endl;
    }

    return 0;
}

/* Sample Input
3
1
10
1101

Sample Output
0
1
6

*/