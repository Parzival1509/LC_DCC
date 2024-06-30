// LC DCC 2024/06/27
// 1791. Find Center of Star Graph
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ? edges[0][0] : edges[0][1];
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> edges(n - 1, {0, 0});
        for(int i = 0; i < n - 1; i++)
            cin >> edges[i][0] >> edges[i][1];
        cout << ob.findCenter(edges) << endl;
    }

    return 0;
}

/* Sample Input
2
4
1 2
2 3
4 2
5
1 2
5 1
1 3
1 4

Sample Output
2
1

*/