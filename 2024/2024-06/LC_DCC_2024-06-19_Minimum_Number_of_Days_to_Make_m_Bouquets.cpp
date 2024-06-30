// LC DCC 2024/06/19
// 1482. Minimum Number of Days to Make m Bouquets
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }
            if (count == k) {
                total++;
                i--;
            }

            if (total >= m)
                return true;
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
            return -1;

        int low = 1, high = 1e9;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid))
                high = mid;
            else low = mid + 1;
        }

        return low;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> bloomDay(n, 0);
        for(int &i: bloomDay)
            cin >> i;
        cout << ob.minDays(bloomDay, m, k) << endl;
    }

    return 0;
}

/* Sample Input
3
5 3 1
1 10 3 10 2
5 3 2
1 10 3 10 2
7 2 3
7 7 7 7 12 7 7

Sample Output
3
-1
12

*/