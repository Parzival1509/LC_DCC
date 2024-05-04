// LC DCC 2024/04/07
// 678. Valid Parenthesis String
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;

        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }

            if (leftMax < 0) return false;
            
            if (leftMin < 0) leftMin = 0;
        }

        return leftMin == 0;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(ob.checkValidString(s)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}

/* Sample Input
3
()
(*)
(*))

Sample Output
true
true
true

*/