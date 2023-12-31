// LC DCC 2023/12/18
// 1913. Maximum Product Difference Between Two Pairs
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int a = INT_MIN, b = INT_MIN, c = INT_MAX, d = INT_MAX;
        for(int i: nums) {
            if(i > a) {
                b = a;
                a = i;
            }
            else b = max(b, i);
            if(i < c) {
                d = c;
                c = i;
            }
            else d = min(d, i);
        }

        return a * b - c * d;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int &i: nums)
            cin >> i;
        cout << ob.maxProductDifference(nums) << endl;
    }

    return 0;
}

/* Sample Input:
2
5
5 6 2 7 4
7
4 2 5 9 7 4 8

Sample Output:
34
64

*/