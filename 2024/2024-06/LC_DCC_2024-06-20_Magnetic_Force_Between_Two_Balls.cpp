// LC DCC 2024/06/20
// 1552. Magnetic Force Between Two Balls
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canWePlace(const vector<int>& arr, int dist, int balls) {
        int countBalls = 1, lastPlaced = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastPlaced >= dist) {
                countBalls++;
                lastPlaced = arr[i];
            }
            if (countBalls >= balls)
                return true;
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1, hi = (position.back() - position[0]) / (m - 1);
        int ans = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canWePlace(position, mid, m)) {
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }

        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> position(n, 0);
        for(int &i: position)
            cin >> i;
        cout << ob.maxDistance(position, m) << endl;
    }

    return 0;
}

/* Sample Input
2
5 3
1 2 3 4 7
6 2
5 4 3 2 1 1000000000

Sample Output
3
999999999

*/