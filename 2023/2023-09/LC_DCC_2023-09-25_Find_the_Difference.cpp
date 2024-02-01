// LC DCC 2023/09/25
// 389. Find the Difference
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    char findTheDifference(string s, string t) {
        // Approach 1: Using vector, S.C. = O(N)
        // vector<int> hshs(26, 0), hsht(26, 0);
        // for(char c: s)
        //     hshs[c - 'a']++;
        // for(char c: t)
        //     hsht[c - 'a']++;
        
        // int i;
        // for(i = 0; i < 26; i++)
        //     if(hshs[i] != hsht[i]) break;
        
        // return 'a' + i;

        // // Approach 2: Using Sum, S.C. = O(1)
        // int sum = t[0];
        // for(int i = 0; i < s.size(); i++)
        //     sum += t[i + 1] - s[i];
        
        // return (char)sum;

        // Approach 3: Using XOR, S.C. = O(1)
        char ch = t[0];
        for(int i = 0; i < s.size(); i++)
            ch ^= s[i] ^ t[i + 1];

        return ch;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s, t;
        cin >> s >> t;
        cout << ob.findTheDifference(s, t) << endl;
    }

    return 0;
}

/* Sample Input:
2
abcd abcde
aaab aabba

Sample Output:
e
b

*/