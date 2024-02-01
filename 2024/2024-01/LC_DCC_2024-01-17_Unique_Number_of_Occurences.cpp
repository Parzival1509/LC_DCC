// LC DCC 2024/01/17
// 1207. Unique Number of Occurrences
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> ump;
        for(auto x: arr)
            ump[x]++;
        unordered_set<int> s;
        for(auto x: ump)
            s.insert(x.second);
        
        return (ump.size() == s.size());
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        if(ob.uniqueOccurrences(arr)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}

/* Sample Input
3
6
1 2 2 1 1 3
2
1 2
10
-3 0 1 -3 1 1 1 -3 10 0

Sample Output
true
false
true

*/