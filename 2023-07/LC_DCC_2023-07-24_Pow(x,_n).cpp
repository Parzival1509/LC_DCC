// LC DCC 2023/07/24
// 50. Pow(x, n)
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
private:
    double myPowHelper(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        
        double res = myPowHelper(x, n / 2);
        res *= res;
        if(n % 2 != 0)
            return (n > 0)? res * x: res / x;
        return res;
    }

public:
    double myPow(double x, int n) {
        return myPowHelper(x, n);
    }    
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        double x;
        int n;
        cin >> x >> n;
        cout << ob.myPow(x, n) << endl;
    }
    
    return 0;
}

/* Sample Input:
3
2.00 10
2.10 3
2.00 -2

Sample Output:
1024
9.261
0.25

*/