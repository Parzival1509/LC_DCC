// LC DCC 2023/03/30
// 87. Scramble String
// Hard

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool DP_helper(unordered_map<string, bool> &isScramblePair, string s1, string s2) {
        int len = s1.size();
        bool res = false;
        if(len == 0) return true;
        else if(len == 1) return s1 == s2;
        else {
            if(isScramblePair.count(s1+s2)) return isScramblePair[s1+s2];
            
            if(s1 == s2) res = true;
            else {
                for(int i=1; i<len && !res; ++i) {
                    res = res || (DP_helper(isScramblePair, s1.substr(0, i), s2.substr(0, i)) && DP_helper(isScramblePair, s1.substr(i, len-i), s2.substr(i, len-i)));
                    res = res || (DP_helper(isScramblePair, s1.substr(0, i), s2.substr(len-i, i)) && DP_helper(isScramblePair, s1.substr(i, len-i), s2.substr(0, len-i)));
                }
            }
            
            return isScramblePair[s1+s2] = res;
        }
    }

    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> isScramblePair;
        return DP_helper(isScramblePair, s1, s2);
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        string s1, s2;
        cin>>s1>>s2;
        cout<<ob.isScramble(s1, s2)<<endl;
    }
    return 0;
}

/* Sample Input:
3
great rgeat
abcde caebd
a a

Sample Output:
1
0
1

*/