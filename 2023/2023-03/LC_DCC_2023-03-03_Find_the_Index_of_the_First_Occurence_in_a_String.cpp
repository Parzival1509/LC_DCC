// LC DCC 2023/03/03
// 28. Find the Index of the First Occurrence in a String
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int strStr(string haystack, string needle) {
        int nh = haystack.size(), nn = needle.size(), i = 0, ptr = -1;

        while(i <= nh-nn) {
            ptr = i;
            if(haystack.substr(i, nn) == needle) return ptr;
            i++;
        }
        return -1;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        string haystack, needle;
        cin>>haystack>>needle;
        cout<<ob.strStr(haystack, needle)<<endl;
    }
    return 0;
}

/* Sample Input:
3
sadbutsad sad
leetcode leeto
mississippi issip

Sample Output:
0
-1
4

*/