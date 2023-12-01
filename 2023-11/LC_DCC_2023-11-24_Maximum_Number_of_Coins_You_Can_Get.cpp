// LC DCC 2023/11/24
// 1561. Maximum Number of Coins You Can Get
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size(), ans = 0, j = n - 2;
        
        for(int i = 0; i < n / 3; i++) {
            ans += piles[j];
            j -= 2;
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> piles(3 * n, 0);
        for(int &i: piles)
            cin >> i;
        cout << ob.maxCoins(piles) << endl;
    }

    return 0;
}

/* Sample Input:
3
2
2 4 1 2 7 8
1
2 4 5
3
9 8 7 6 5 1 2 3 4

Sample Output:
9
4
18

*/