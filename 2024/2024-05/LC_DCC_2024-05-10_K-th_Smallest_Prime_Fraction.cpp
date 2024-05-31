// LC DCC 2024/05/10
// 786. K-th Smallest Prime Fraction
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1, mid;
        vector<int> res;

        while (left <= right) {
            mid = left + (right - left) / 2;
            int j = 1, total = 0, num = 0, den = 0;
            double maxFrac = 0;
            for (int i = 0; i < n; ++i) {
                while (j < n && arr[i] >= arr[j] * mid)
                    ++j;

                total += n - j;
                if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
                    maxFrac = arr[i] * 1.0 / arr[j];
                    num = i;
                    den = j;
                }
            }

            if (total == k) {
                res = {arr[num], arr[den]};
                break;
            }

            if (total > k)
                right = mid;
            else left = mid;
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
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        vector<int> ans = ob.kthSmallestPrimeFraction(arr, k);
        cout << ans[0] << ' ' << ans[1] << endl;
    }

    return 0;
}

/* Sample Input
2
4 3
1 2 3 5
2 1
1 7

Sample Output
2 5
1 7

*/