// LC DCC 2024/03/01
// 2864. Maximum Odd Binary Number
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // // Approach 1:
        // // T.C. = O(N), S.C. = O(N)
        // int cnt1 = 0, cnt0 = 0;
        // for (auto a : s) {
        //     if (a == '1') cnt1++;
        //     else cnt0++;
        // }
        // string ans = string(cnt1 - 1, '1') + string(cnt0, '0') + '1';

        // return ans;

        // Approach 2:
        // T.C. = O(N * log N), S.C. = O(1)
        sort(s.rbegin(), s.rend());
        for (int i = s.size() - 1; i >= 0; i--)
            if (s[i] == '1')
                swap(s[i], s[s.size() - 1]);

        return s;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.maximumOddBinaryNumber(s) << endl;
    }

    return 0;
}

/* Sample Input
2
010
0101

Sample Output
001
1001

*/