// LC DCC 2024/01/03
// 2125. Number of Laser Beams in a Bank
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int calc(string& s) {
        int count = 0;
        for (char c : s)
            count += c - '0';

        return count;
    }

    int numberOfBeams(vector<string>& bank) {
        int prevRowCount = 0;
        int total = 0;

        for (string& row : bank) {
            int curRowCount = calc(row);
            if (curRowCount == 0)
                continue;

            total += curRowCount * prevRowCount;
            prevRowCount = curRowCount;
        }

        return total;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<string> bank(m, "");
        for(auto &i: bank)
            cin >> i;
        cout << ob.numberOfBeams(bank) << endl;
    }

    return 0;
}

/* Sample Input:
2
4 6
011001
000000
010100
001000
3 3
000
111
000

Sample Output:
8
0

*/