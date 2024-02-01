// LC DCC 2024/01/13
// 1347. Minimum Number of Steps to Make Two Strings Anagram
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count_s(26, 0), count_t(26, 0);

        for(char ch: s)
            count_s[ch - 'a']++;
        for(char ch: t)
            count_t[ch - 'a']++;

        int steps = 0;
        for(int i = 0; i < 26; i++)
            steps += abs(count_s[i] - count_t[i]);

        return steps / 2;  
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string s, t;
        cin >> s >> t;
        cout << ob.minSteps(s, t) << endl;
    }

    return 0;
}

/* Sample Input
3
aba bab
leetcode practice
anagram mangaar

Sample Output
1
5
0

*/