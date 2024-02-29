// LC DCC 2024/02/03
// 1043. Partition Array for Maximum Sum
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int N = arr.size(), K = k + 1;
        int dp[K];
        memset(dp, 0, sizeof(dp));

        for (int start = N - 1; start >= 0; start--) {
            int currMax = 0;
            int end = min(N, start + k);
            
            for (int i = start; i < end; i++) {
                currMax = max(currMax, arr[i]);
                dp[start % K] = max(dp[start % K], dp[(i + 1) % K] + currMax * (i - start + 1));
            }
        }
        
        return dp[0];
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        cout << ob.maxSumAfterPartitioning(arr, k) << endl;
    }

    return 0;
}

/* Sample Input
3
7 3
1 15 7 9 2 5 10
11 4
1 4 1 5 7 3 6 1 9 9 3
1 1
1

Sample Output
84
83
1

*/