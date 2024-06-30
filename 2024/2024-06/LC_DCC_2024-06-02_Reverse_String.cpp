// LC DCC 2024/06/02
// 344. Reverse String
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin >> n;
        vector<char> s(n, ' ');
        for(auto &i: s)
            cin >> i;
        ob.reverseString(s);
        for(auto i: s)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
5 hello
6 Hannah

Sample Output
o l l e h 
h a n n a H 

*/