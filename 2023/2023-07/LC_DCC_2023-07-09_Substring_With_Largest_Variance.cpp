// LC DCC 2023/07/09
// 2272. Substring With Largest Variance
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int largestVariance(string s) {
        int n = s.size(), res = 0;

        for (char p = 'a'; p <= 'z'; p++)
            for (char q = 'a'; q <= 'z'; q++) {
                if (p == q) continue;

                int pCount = 0, qCount = 0;
                bool canExtendprevQ = false;
                
                for (auto c: s) {
                    if (c == p) pCount++;
                    else if (c == q) qCount++;
                    
                    if (qCount > 0)
                        res = max(res, pCount - qCount);
                    else if (qCount == 0 && canExtendprevQ)
                        res = max(res, pCount - 1);
                
                    if (qCount > pCount) {
                        qCount = pCount = 0;
                        canExtendprevQ = true;
                    }
                }
            }

        return res;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while(T--) {
        string s;
        cin >> s;
        cout << ob.largestVariance(s) << endl;
    }
    return 0;
}

/* Sample Input:
2
4 2
1 3 5 1
2 2
1 3

Sample Output:
3
0

*/