// LC DCC 2024/05/28
// 1208. Get Equal Substrings Within Budget
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), start = 0, current_cost = 0, max_length = 0;
        for (int end = 0; end < n; ++end) {
            current_cost += abs(s[end] - t[end]);
            while (current_cost > maxCost) {
                current_cost -= abs(s[start] - t[start]);
                ++start;
            }
            max_length = max(max_length, end - start + 1);
        }

        return max_length;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        string s, t;
        int maxCost;
        cin >> s >> t >> maxCost;
        cout << ob.equalSubstring(s, t, maxCost) << endl;
    }

    return 0;
}

/* Sample Input
3
abcd bcdf 3
abcd cdef 3
abcd acde 0

Sample Output
3
1
1

*/