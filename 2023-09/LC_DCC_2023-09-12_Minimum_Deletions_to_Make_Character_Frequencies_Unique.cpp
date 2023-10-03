// LC DCC 2023/09/12
// 1647. Minimum Deletions to Make Character Frequencies Unique
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> cnt;
        int deletions = 0;
        unordered_set<int> used_frequencies;
        
        for(char c: s)
            cnt[c]++;
        
        for(auto& kv: cnt) {
            int freq = kv.second;
            while(freq > 0 && used_frequencies.find(freq) != used_frequencies.end()) {
                freq--;
                deletions++;
            }
            used_frequencies.insert(freq);
        }
        
        return deletions;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.minDeletions(s) << endl;
    }

    return 0;
}

/* Sample Input:
3
aab
aaabbbcc
ceabaacb

Sample Output:
0
2
2

*/