// LC DCC 2024/02/07
// 451. Sort Characters By Frequency
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(string &s1, string &s2) {
        return s1.size() > s2.size();
    }

    string frequencySort(string s) {
        vector<string> v(127);
        for (auto i : s)
            v[i] += i;
        sort(v.begin(), v.end(), cmp);
        string res;
        for (auto i : v)
            res += i;
        
        return res;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.frequencySort(s) << endl;
    }

    return 0;
}

/* Sample Input
3
tree
aaaccc
Aabb

Sample Output
eert
aaaccc
bbAa

*/