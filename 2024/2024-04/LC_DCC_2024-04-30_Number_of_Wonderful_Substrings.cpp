// LC DCC 2024/04/30
// 1915. Number of Wonderful Substrings
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> count(1024, 0);
        long long result = 0;
        int prefixXor = 0;
        count[prefixXor] = 1;

        for (char ch : word) {
            int charIndex = ch - 'a';
            prefixXor ^= 1 << charIndex;
            result += count[prefixXor];
            for (int i = 0; i < 10; i++)
                result += count[prefixXor ^ (1 << i)];
            count[prefixXor]++;
        }

        return result;
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        string word;
        cin >> word;
        cout << ob.wonderfulSubstrings(word) << endl;
    }

    return 0;
}

/* Sample Input
3
aba
aabb
he

Sample Output
4
9
2

*/