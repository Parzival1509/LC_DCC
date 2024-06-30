// LC DCC 2024/06/09
// 974. Subarray Sums Divisible by K
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n = a.size(), csum = 0, ans = 0;
        vector<int> rem(k, 0);
        rem[0] = 1;
        for (int i = 0; i < n; i++) {
            csum = (csum % k + a[i] % k + k) % k;
            rem[csum]++;
        }

        for (int i = 0; i < k; i++)
            ans += (rem[i] * (rem[i] - 1)) / 2;

        return ans;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n, 0);
        for(int &i: a)
            cin >> i;
        cout << ob.subarraysDivByK(a, k) << endl;
    }

    return 0;
}

/* Sample Input
2
6 5
4 5 0 -2 -3 1
1 9
5

Sample Output
7
0

*/