// LC DCC 2023/11/27
// 935. Knight Dialer
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;
    int cache[5001][10];

    vector<vector<int>> MOVES = {{4, 6}, {8, 6}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

    int solve(int remaining, vector<int>& nextNumbers) {
        if(remaining == 1)
            return nextNumbers.size();

        int count = 0;
        for(int nextNumber: nextNumbers) {
            int cur = cache[remaining][nextNumber];
            if(cur == 0) {
                cur = solve(remaining - 1, MOVES[nextNumber]);
                cache[remaining][nextNumber] = cur;
            }
            count += cur;
            count %= mod;
        }

        return count;
    }

    int knightDialer(int n) {
        vector<int> nextNumbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        return solve(n, nextNumbers);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.knightDialer(n) << endl;
    }

    return 0;
}

/* Sample Input:
3
1
2
3131

Sample Output:
10
20
136006598

*/