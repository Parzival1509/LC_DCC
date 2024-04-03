// LC DCC 2024/03/11
// 791. Custom Sort String
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> charCount;
        for (char c : order)
            charCount[c] = 0;
        
        for (char c : s)
            if (charCount.find(c) != charCount.end())
                charCount[c]++;
        
        string sortedS;
        for (char c : order)
            sortedS.append(charCount[c], c);
        
        for (char c : s)
            if (charCount.find(c) == charCount.end())
                sortedS.push_back(c);
        
        return sortedS;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string order, s;
        cin >> order >> s;
        cout << ob.customSortString(order, s) << endl;
    }

    return 0;
}

/* Sample Input
2
cba abcd
bcafg abcd

Sample Output
cbad
bcad

*/