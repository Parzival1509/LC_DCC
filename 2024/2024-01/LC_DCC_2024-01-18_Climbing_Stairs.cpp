// LC DCC 2024/01/18
// 70. Climbing Stairs
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n < 4) return n;

        int one = 1, two = 2;
        for(int i = 2; i < n; i++) {
            int tmp = one;
            one = two;
            two = one + tmp;
        }

        return two;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.climbStairs(n) << endl;
    }

    return 0;
}

/* Sample Input
4
2
3
4
5

Sample Output
2
3
5
8

*/