// LC DCC 2024/03/05
// 1750. Minimum Length of String After Deleting Similar Ends
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right && s[left] == s[right]) {
            char ch = s[left];
            while (left <= right && s[left] == ch)
                left++;
            while (right >= left && s[right] == ch)
                right--;
        }

        return right - left + 1;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.minimumLength(s) << endl;
    }

    return 0;
}

/* Sample Input
3
ca
cabaabac
aabccabba

Sample Output
2
0
3

*/