// LC DCC 2023/04/23
// 1416. Restore The Array
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.length(), mod = 1e9 + 7;
        vector<int> m(n + 1, 0);
        m[n] = 1;
        // Iterate over the string from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                m[i] = 0;
                continue;
            }
            long long res = 0;
            // Compute the number formed by the substring s[i:j+1]
            for (int j = i; j < n; j++) {
                res = res * 10 + (s[j] - '0');
                if (res > k) break;
                // Add the number of arrays formed by the substring s[j+1:]
                m[i] = (m[i] + m[j + 1]) % mod;
            }
        }
        return m[0];
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        string s;
        int k;
        cin>>s>>k;
        cout<<ob.numberOfArrays(s, k)<<endl;
    }
    return 0;
}

/* Sample Input:
3
1000 10000
1000 10
1317 2000

Sample Output:
1
0
8

*/