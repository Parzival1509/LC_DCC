// LC DCC 2023/10/26
// 823. Binary Trees With Factors
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        unordered_set<int> s(arr.begin(), arr.end());
        unordered_map<int, int> dp;

        for(int x: arr) dp[x] = 1;
        
        for(int i: arr) {
            for(int j: arr) {
                if(j > sqrt(i)) break;

                if(i % j == 0 && s.find(i / j) != s.end()) {
                    ll temp = (ll)dp[j] * dp[i / j];
                    if(i / j == j)
                        dp[i] = (dp[i] + temp) % MOD;
                    else dp[i] = (dp[i] + temp * 2) % MOD;
                }
            }
        }
        
        int result = 0;
        for(auto& it: dp)
            result = (result + it.second) % MOD;

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        cout << ob.numFactoredBinaryTrees(arr) << endl;
    }

    return 0;
}

/* Sample Input:
2
2
2 4
4
2 4 5 10

Sample Output:
3
7


*/