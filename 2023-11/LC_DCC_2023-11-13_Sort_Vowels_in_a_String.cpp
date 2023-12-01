// LC DCC 2023/11/13
// 2785. Sort Vowels in a String
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string sortVowels(string s) {
        // // Approach 1:
        // vector<char> vowels;
        // vector<int> ind;

        // for(int i = 0; i < s.size(); i++)
        //     if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
        //         vowels.push_back(s[i]);
        //         ind.push_back(i);
        //     }

        // sort(vowels.begin(), vowels.end());

        // for(int i = 0; i < ind.size(); i++)
        //     s[ind[i]] = vowels[i];

        // Approach 2:
        vector<char> vowels;
        string tmp = "aeiouAEIOU";

        for(int i = 0; i < s.size(); i++)
            if(tmp.find(s[i]) != string::npos)
                vowels.push_back(s[i]);

        sort(vowels.begin(), vowels.end(), greater<char>());

        for(int i = 0; i < s.size(); i++)
            if(tmp.find(s[i]) != string::npos) {
                s[i] = vowels.back();
                vowels.pop_back();
            }

        return s;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        cin >> s;
        string ans = ob.sortVowels(s);
        cout << ans << endl;
    }

    return 0;
}

/* Sample Input:
2
lEetcOde
lYmpH

Sample Output:
lEOtcede
lYmpH

*/