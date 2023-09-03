// LC DCC 2023/08/22
// 168. Excel Sheet Column Title
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n > 0) {
            n--;
            int curr = n % 26;
            n = n / 26;
            ans.push_back(curr + 'A');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        cout << ob.convertToTitle(n) << endl;
    }

    return 0;
}

/* Sample Input:
3
1
28
701

Sample Output:
A
AB
ZY

*/