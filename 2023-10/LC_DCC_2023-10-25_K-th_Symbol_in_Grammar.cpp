// LC DCC 2023/10/25
// 779. K-th Symbol in Grammar
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int kthGrammar(int n, int k) {
        // Approach 1:
        // Initialize a flag to track if the values of k and first element are the same.
        bool areValuesSame = true; 
        n = pow(2, n - 1);

        while(n != 1) {
            n /= 2;
            // If k is in the second half of the row, adjust k and toggle the flag.
            if(k > n) {
                k -= n;
                areValuesSame = !areValuesSame;
            }
        }

        // Return 0 if the flag indicates that the values are the same, else return 1.
        return (areValuesSame? 0: 1);

        // // Approach 2: Recursion
        // if(n == 1) return 0;

        // int length = 1 << (n - 2);

        // if(k <= length)
        //     return kthGrammar(n - 1, k);
        // return 1 - kthGrammar(n - 1, k - length);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << ob.kthGrammar(n, k) << endl;
    }

    return 0;
}

/* Sample Input:
3
1 3 2 5 3 N 9
1 2 3


Sample Output:
1 3 9
1 3


*/