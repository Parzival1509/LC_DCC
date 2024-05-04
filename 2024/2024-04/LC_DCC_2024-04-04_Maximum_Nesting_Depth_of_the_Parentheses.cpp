// LC DCC 2024/04/04
// 1614. Maximum Nesting Depth of the Parentheses
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxDepth(string s) {
        int ct = 0, max_num = 0;
        for (char c : s) {
            if (c == '(') {
                ct++;
                if (max_num < ct)
                    max_num = ct;
            }
            else if (c == ')')
                ct--;
        }

        return max_num;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.maxDepth(s) << endl;
    }

    return 0;
}

/* Sample Input
2
(1+(2*3)+((8)/4))+1
(1)+((2))+(((3)))

Sample Output
3
3

*/