// LC DCC 2023/02/01
// 1071. Greatest Common Divisor of Strings
// Easy

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    string gcdOfStrings(string s, string t) {
        if(s+t == t+s) return s.substr(0, __gcd(s.size(), t.size()));
        return "";
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        string s, t;
        cin>>s>>t;
        cout<<ob.gcdOfStrings(s, t)<<endl;
    }
    return 0;
}

/* Sample Input:
3
ABCABC ABC
ABABAB ABAB
LEET CODE

Sample Output:
ABC
AB


*/