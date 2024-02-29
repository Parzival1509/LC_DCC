// LC DCC 2024/02/19
// 231. Power of Two
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        // // Approach 1: Loop
        // // T.C. = O(log N), S.C. = O(1)
        // while (n % 2 == 0)
        //     n /= 2;
        
        // return n == 1;

        // // Approach 2: Recursion
        // // T.C. = O(log N), S.C. = O(log N)
        // return ((n == 1) || ((n % 2 == 0) && isPowerOfTwo(n / 2)));

        // // Approach 3: Bit Manipulation
        // // T.C. = O(1), S.C. = O(1)
        // return ((n & (n - 1)) == 0);

        // Approach 4: Builtin Popcount
        // T.C. = O(log N), S.C. = O(1)
        return (__builtin_popcount(n) == 1);
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.isPowerOfTwo(n) << endl;
    }

    return 0;
}

/* Sample Input
5
1
3
16
2048
-2147483648

Sample Output
1
0
1
1
0

*/