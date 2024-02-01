// LC DCC 2023/03/02
// 443. String Compression
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), i = 0, ptr = 0;

        while(i < n) {
            char ch = chars[i];
            int ct = 0;
            while(i < n && chars[i] == ch) {
                ct++;
                i++;
            }
            
            chars[ptr] = ch;
            ptr++;
            if(ct > 1) {
                string s = to_string(ct);
                for(int j=0; j<s.size(); j++) {
                    chars[ptr] = s[j];
                    ptr++;
                }
            }
        }
        return ptr;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        vector<char> chars(n);
        for(int i=0; i<n; i++)
            cin>>chars[i];
        getchar();
        int ct = ob.compress(chars);
        cout<<ct<<endl;
        for(int i=0; i<ct; i++)
            cout<<chars[i];
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
3
7
aabbccc
1
a
13
abbbbbbbbbbbb

Sample Output:
6
a2b2c3
1
a
4
ab12

*/