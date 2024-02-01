// LC DCC 2023/10/30
// 1356. Sort Integers by The Number of 1 Bits
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    static bool cmp(int& a, int& b) {
        if(__builtin_popcount(a) != __builtin_popcount(b))
            return __builtin_popcount(a) < __builtin_popcount(b);
        return a < b;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
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
        vector<int> ans = ob.sortByBits(arr);
        for(int i: arr)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
9
0 1 2 3 4 5 6 7 8
11
1024 512 256 128 64 32 16 8 4 2 1

Sample Output:
0 1 2 4 8 3 5 6 7 
1 2 4 8 16 32 64 128 256 512 1024 

*/