// LC DCC 2024/05/09
// 3075. Maximize Happiness of Selected Children
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(begin(happiness), end(happiness), greater<int>());
        int i = 0;
        long long res = 0;

        while(k--) {
            happiness[i] = max(happiness[i] - i, 0);
            res += happiness[i++];
        }

        return res;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> happiness(n, 0);
        for(int &i: happiness)
            cin >> i;
        cout << ob.maximumHappinessSum(happiness, k) << endl;
    }

    return 0;
}

/* Sample Input
3
3 2
1 2 3
4 2
1 1 1 1
4 1
2 3 4 5

Sample Output
4
1
5

*/