// LC DCC 2023/09/24
// 799. Champagne Tower
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(query_row + 1, vector<double>(query_row + 1, 0.0));
        tower[0][0] = poured;

        for(int row = 0; row < query_row; row++)
            for(int glass = 0; glass <= row; glass++) {
                double excess = (tower[row][glass] - 1.0) / 2.0;
                if(excess > 0) {
                    tower[row + 1][glass] += excess;
                    tower[row + 1][glass + 1] += excess;
                }
                tower[row][glass] = 1.0;
            }

        return min(1.0, tower[query_row][query_glass]);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int poured, query_row, query_glass;
        cin >> poured >> query_row >> query_glass;
        cout << ob.champagneTower(poured, query_row, query_glass) << endl;
    }

    return 0;
}

/* Sample Input:
3
1 1 1
2 1 1
100000009 33 17

Sample Output:
0.00000
0.50000
1.00000

*/