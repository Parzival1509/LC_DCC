// LC DCC 2023/04/26
// 258. Add Digits
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int addDigits(int num) {
        int n = num;
        while(num > 9) {
            n = num, num = 0;
            while(n != 0) {
                num += n % 10;
                n /= 10;
            }
        }
        return num;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        cout<<ob.addDigits(n)<<endl;
    }
    return 0;
}

/* Sample Input:
3
0
38
101

Sample Output:
0
2
2

*/