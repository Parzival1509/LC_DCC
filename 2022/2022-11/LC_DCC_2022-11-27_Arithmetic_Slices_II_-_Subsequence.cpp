// LC DCC 2022/11/27
// 446. Arithmetic Slices II - Subsequence
// Hard

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();
bool cmp(pair<string, int> A, pair<string, int> B){
    if(A.first != B.first)
        return A.second < B.second;
    return B.first > A.first;
}

// Baijnath's Sol
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() <= 2)
            return 0;
        vector<unordered_map<int, int>> opt(A.size()); 
        int ans = 0;
        for(int i=1; i<A.size(); ++i) {
            for(int j=0; j<i; ++j) {
                long d = (long)A[i] - A[j];
                if(d<=INT_MIN || d>INT_MAX)
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
        for(int i = 0; i < n; i++)
            cin >> a[i];
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