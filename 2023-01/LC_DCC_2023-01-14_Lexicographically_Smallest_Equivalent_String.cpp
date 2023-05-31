// LC DCC 2023/01/14
// 1061. Lexicographically Smallest Equivalent String
// Medium

#include <bits/stdc++.h>
using namespace std;

// Baijnath's Sol
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char map[26];
        for(int i=0; i<26; i++)
            map[i] = i+'a';
        for(int i=0; i<s1.size(); i++){
            char replace = max(map[s1[i] - 'a'],map[s2[i] - 'a']); //Bigger element
            char put = min(map[s1[i] - 'a'],map[s2[i] - 'a']); // Smaller element
            for(int i=0; i<26; i++){
                if(map[i] == replace)
                    map[i] = put;   // Replace all the bigger characters with it's smallest equivalent
            }
        }

        string ans = "";
        for(int i=0; i<baseStr.size(); i++)
            ans += map[baseStr[i] - 'a'];
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        string s1, s2, baseStr;
        cin>>s1>>s2>>baseStr;
        cout<<ob.smallestEquivalentString(s1, s2, baseStr)<<endl;
    }
    return 0;
}

/* Sample Input
3
parker morris parser
hello world hold
leetcode programs sourcecode

Sample Output
makkek
hdld
aauaaaaada

*/