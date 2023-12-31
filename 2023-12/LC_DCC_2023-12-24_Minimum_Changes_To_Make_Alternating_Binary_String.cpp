// LC DCC 2023/12/24
// 1758. Minimum Changes To Make Alternating Binary String
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minOperations(string s) {
        int a = 0, b = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i & 1) a += (s[i] - '0' == 1);
            else a += (s[i] - '0' == 0);

            if(i & 1) b += (s[i] - '0' == 0);
            else b += (s[i] - '0' == 1);
        }

        return min(a, b);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.minOperations(s) << endl;
    }

    return 0;
}

/* Sample Input:
3
0100
10
1111

Sample Output:
1
0
2

*/