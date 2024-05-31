// LC DCC 2024/05/03
// 165. Compare Version Numbers
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string& v1, string& v2) {
        int n1 = v1.size(), n2 = v2.size(), x1 = 0, x2 = 0;
        for (int i = 0, j = 0; i < n1 || j < n2; i++, j++) {
            while (i < n1 && v1[i] != '.')
                x1 = 10 * x1 + (v1[i++] - '0');
            while (j < n2 && v2[j] != '.')
                x2 = 10 * x2 + (v2[j++] - '0');
            
            if (x1 < x2) return -1;
            if (x1 > x2) return 1;
            
            x1 = 0;
            x2 = 0;
        }

        return 0;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        string v1, v2;
        cin >> v1 >> v2;
        cout << ob.compareVersion(v1, v2) << endl;
    }

    return 0;
}

/* Sample Input
3
1.01 1.001
1.0 1.0.0
0.1 1.1

Sample Output
0
0
-1

*/