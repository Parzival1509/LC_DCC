// LC DCC 2023/09/27
// 880. Decoded String at Index
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long length = 0;
        int i = 0;
        
        while(length < k) {
            if(isdigit(s[i]))
                length *= s[i] - '0';
            else length++;

            i++;
        }
        
        for(int j = i - 1; j >= 0; j--) {
            if(isdigit(s[j])) {
                length /= s[j] - '0';
                k %= length;
            }
            else {
                if(k == 0 || k == length)
                    return string(1, s[j]);
                
                length--;
            }
        }
        
        return "";
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        int k;
        cin >> s >> k;
        cout << ob.decodeAtIndex(s, k) << endl;
    }

    return 0;
}

/* Sample Input:
3
leet2code3 10
ha22 5
a2345678999999999999999 1

Sample Output:
o
h
a

*/