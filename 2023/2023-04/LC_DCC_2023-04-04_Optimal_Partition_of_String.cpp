// LC DCC 2023/04/04
// 2405. Optimal Partition of String
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int partitionString(string s) {
        int ct = 0;

        // // Approach 1: Using Map
        // map<char, int> hsh;
        // for(int i=0; i<s.size(); i++) {
        //     if(hsh.find(s[i]) != hsh.end()) {
        //         ct++;
        //         hsh.clear();
        //     }
        //     hsh[s[i]]++;
        // }
        // if(hsh.size() > 0) ct++;

        // Approach 2: Using Array
        int hsh[26] = {0};
        for(int i=0; i<s.size(); i++) {
            if(hsh[s[i] - 'a']) {
                ct++;
                memset(hsh, 0, sizeof(hsh));
            }
            hsh[s[i] - 'a']++;
        }

        for(auto el: hsh)
            if(el > 0) {
                ct++;
                break;
            }

        return ct;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        string s;
        cin>>s;
        cout<<ob.partitionString(s)<<endl;
    }
    return 0;
}

/* Sample Input:
2
abacaba
ssssss

Sample Output:
4
6

*/