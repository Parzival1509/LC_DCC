// LC DCC 2024/02/22
// 997. Find the Town Judge
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> hsh(n + 1, 0), f(n + 1, 0);
        for (int i = 0; i < trust.size(); i++) {
            f[trust[i][0]]++;
            hsh[trust[i][1]]++;
        }

        for (int i = 1; i <= n; i++)
            if (hsh[i] == n - 1 && f[i] == 0)
                return i;
        
        return -1;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> trust(m, {0, 0});
        for(int i = 0; i < m; i++)
            cin >> trust[i][0] >> trust[i][1];
        cout << ob.findJudge(n, trust) << endl;
    }

    return 0;
}

/* Sample Input
3

2 1
1 2

3 2
1 3
2 3

3 3
1 3
2 3
3 1

Sample Output
2
3
-1

*/