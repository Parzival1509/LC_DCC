// LC DCC 2023/02/14
// 67. Add Binary
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, i = a.size()-1, j = b.size()-1;
        string res = "";
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return res;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        string a, b;
        cin>>a>>b;
        cout<<ob.addBinary(a, b)<<endl;
    }
    return 0;
}

/* Sample Input:
2
11 1
1011 1010

Sample Output:
100
10101

*/