// LC DCC 2024/06/17
// 633. Sum of Square Numbers
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int divisor = 2; divisor * divisor <= c; divisor++) {
            if (c % divisor == 0) {
                int exponentCount = 0;
                while (c % divisor == 0) {
                    exponentCount++;
                    c /= divisor;
                }
                
                if (divisor % 4 == 3 && exponentCount % 2 != 0)
                    return false;
            }
        }

        return (c % 4) != 3;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int c;
        cin >> c;
        if(ob.judgeSquareSum(c)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}

/* Sample Input
2
5
3

Sample Output
true
false

*/