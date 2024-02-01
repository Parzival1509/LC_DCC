// LC DCC 2023/11/14
// 1930. Unique Length-3 Palindromic Subsequences
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int countPalindromicSubsequence(string inputString) {
        // Arrays to store the minimum and maximum occurrences of each character in the input string
        vector<int> minExist(26, INT_MAX), maxExist(26, INT_MIN);

        for(int i = 0; i < inputString.size(); i++) {
            int charIndex = inputString[i] - 'a';
            minExist[charIndex] = min(minExist[charIndex], i);
            maxExist[charIndex] = max(maxExist[charIndex], i);
        }

        int uniqueCount = 0;

        // Iterate over each character in the alphabet
        for(int charIndex = 0; charIndex < 26; charIndex++) {
            // Check if the character has occurred in the input string
            if(minExist[charIndex] == INT_MAX || maxExist[charIndex] == INT_MIN)
                continue;

            // Set to store unique characters between the minimum and maximum occurrences
            unordered_set<char> uniqueCharsBetween;
            // Iterate over the characters between the minimum and maximum occurrences
            for(int j = minExist[charIndex] + 1; j < maxExist[charIndex]; j++)
                uniqueCharsBetween.insert(inputString[j]);

            uniqueCount += uniqueCharsBetween.size();
        }

        return uniqueCount;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string inputString;
        cin >> inputString;
        cout << ob.countPalindromicSubsequence(inputString) << endl;
    }

    return 0;
}

/* Sample Input:
3
aabca
adc
bbcbaba

Sample Output:
3
0
4

*/