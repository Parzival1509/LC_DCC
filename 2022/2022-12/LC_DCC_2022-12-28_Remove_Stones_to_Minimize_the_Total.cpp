// LC DCC 2022/12/28
// 1962. Remove Stones to Minimize the Total
// Medium

#include <bits/stdc++.h>
using namespace std;

// Good T.C.
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int cnt[10001] = {};
        for(int p: piles) cnt[p]++;
        int i = 10000, sum = 0;
        for (int i=10000; i>=1; i--) {
            int tmp = min(cnt[i], k);
            cnt[i-i/2] += tmp;
            cnt[i] -= tmp;
            k -= tmp;
            sum += cnt[i]*i;
        }
        return sum;
    }
};

// // My Sol
// class Solution {
// public:
//     int minStoneSum(vector<int>& piles, int k) {
//         int n = piles.size(), ans = 0;
//         multiset<int> st;
//         for(int i=0; i<n; i++) {
//             st.insert(piles[i]);
//             ans += piles[i];
//         }
//         while(k--) {
//             auto it = --(st.end());
//             int tmp = *it;
//             st.erase(it);
//             st.insert(ceil(tmp/2.0));
//             ans -= floor(tmp/2.0);
//         }
//         return ans;
//     }
// };

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n, k;
        cin>>n>>k;
        vector<int> piles(n);
        for(int i=0; i<n; i++)
            cin>>piles[i];
        cout<<ob.minStoneSum(piles, k)<<endl;
    }
    return 0;
}

/* Sample Input
3
3 2
5 4 9
4 3
4 3 6 7
1 10000
10000

Sample Output
12
12
1

*/