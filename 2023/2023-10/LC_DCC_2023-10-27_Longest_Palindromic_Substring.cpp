// LC DCC 2023/10/27
// 5. Longest Palindromic Substring
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> expandAroundCenter(string &s, int i, int j) {
        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            --i;
            ++j;
        }

        return {i + 1, j - 1};
    }

    string longestPalindrome(string s) {
        if(s.empty()) return "";
        
        // Approach 1: Using EAC (Expand Around Center) Method
        vector<int> ind = {0, 0};
        for(int i = 0; i < s.length(); ++i) {
            vector<int> odd = expandAroundCenter(s, i, i);
            if(odd[1] - odd[0] > ind[1] - ind[0])
                ind = odd;

            if(i + 1 < s.length() && s[i] == s[i + 1]) {
                vector<int> even = expandAroundCenter(s, i, i + 1);
                if(even[1] - even[0] > ind[1] - ind[0])
                    ind = even;
            }
        }

        return s.substr(ind[0], ind[1] - ind[0] + 1);
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.longestPalindrome(s) << endl;
    }

    return 0;
}

/* Sample Input:
2
babad
cbbd

Sample Output:
bab
bb

*/