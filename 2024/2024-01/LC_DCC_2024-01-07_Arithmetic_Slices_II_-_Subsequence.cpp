// LC DCC 2024/01/07
// 446. Arithmetic Slices II - Subsequence
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() <= 2) return 0;
        
        vector<unordered_map<int, int>> opt(A.size()); 
        int ans = 0;
        for(int i = 1; i < A.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                long d = (long)A[i] - A[j];
                if(d <= INT_MIN || d > INT_MAX)
                    continue;
                int diff = (int)d;
                if(opt[j].find(diff) != opt[j].end()) {
                    opt[i][diff] += opt[j][diff];
                    ans += opt[j][diff];
                }
                opt[i][diff]++; 
            }
        }

        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &i: a)
            cin >> i;
        cout << ob.numberOfArithmeticSlices(a) << endl;
    }
    
    return 0;
}

/* Sample Input
2
5
2 4 6 8 10
5
7 7 7 7 7

Sample Output
7
16

*/