// LC DCC 2024/04/24
// 1137. N-th Tribonacci Number
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int nums[38];
        nums[0] = 0, nums[1] = nums[2] = 1;
        for (int i = 3; i <= n; i++)
            nums[i] = nums[i - 1] + nums[i - 2] + nums[i - 3];

        return nums[n];
    }
};

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges(E, {0, 0});
        for(int i = 0; i < E; i++)
            cin >> edges[i][0] >> edges[i][1];

        Solution ob;
        vector<int> ans = ob.findMinHeightTrees(V, edges);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
4
25

Sample Output
4
1389537

*/