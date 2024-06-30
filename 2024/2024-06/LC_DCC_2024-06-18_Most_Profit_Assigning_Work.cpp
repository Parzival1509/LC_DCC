// LC DCC 2024/06/18
// 826. Most Profit Assigning Work
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxDifficulty = *max_element(difficulty.begin(), difficulty.end());
        vector<int> maxProfitUpToDifficulty(maxDifficulty + 1, 0);

        for (int i = 0; i < difficulty.size(); ++i)
            maxProfitUpToDifficulty[difficulty[i]] = max(maxProfitUpToDifficulty[difficulty[i]], profit[i]);

        for (int i = 1; i <= maxDifficulty; ++i)
            maxProfitUpToDifficulty[i] = max(maxProfitUpToDifficulty[i], maxProfitUpToDifficulty[i - 1]);

        int totalProfit = 0;
        for (int ability : worker) {
            if (ability > maxDifficulty)
                totalProfit += maxProfitUpToDifficulty[maxDifficulty];
            else totalProfit += maxProfitUpToDifficulty[ability];
        }

        return totalProfit;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> difficulty(n, 0), profit(n, 0), worker(m, 0);
        for(int &i: difficulty)
            cin >> i;
        for(int &i: profit)
            cin >> i;
        for(int &i: worker)
            cin >> i;
        cout << ob.maxProfitAssignment(difficulty, profit, worker) << endl;
    }

    return 0;
}

/* Sample Input
2
5 4
2 4 6 8 10
10 20 30 40 50
4 5 6 7
3 3
85 47 57
24 66 99
40 25 25

Sample Output
100
0

*/