// LC DCC 2023/10/23
// 342. Power of Four
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n > 3) {
            if(n % 4)
                return false;
            n /= 4;
        }
        
        return n == 1;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        if(ob.isPowerOfFour(n)) cout << "true ";
        else cout << "false ";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
3
1
5
16

Sample Output:
true 
false 
true 
    
*/