// LC DCC 2023/12/22
// 1422. Maximum Score After Splitting a String
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> zeroes(n, 0), ones(n, 0);

        zeroes[0] = (s[0] == '0');
        for(int i = 1; i < n; i++)
            zeroes[i] += zeroes[i - 1] + (s[i] == '0');

        ones[n - 1] = (s[n - 1] == '1');
        for(int i = n - 2; i >= 0; i--)
            ones[i] += ones[i + 1] + (s[i] == '1');

        int ans = 0;
        for(int i = 0; i < n - 1; i++)
            ans = max(ans, zeroes[i] + ones[i + 1]);

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.maxScore(s) << endl;
    }

    return 0;
}

/* Sample Input:
3
011101
00111
1111

Sample Output:
5
5
3

*/