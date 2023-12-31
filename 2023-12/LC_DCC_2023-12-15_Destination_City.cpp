// LC DCC 2023/12/15
// 1436. Destination City
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> hsh;
        for(auto i: paths)
            hsh[i[0]]++;

        for(auto i: paths)
            if(hsh.find(i[1]) == hsh.end())
                return i[1];

        return "";
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<string>> paths(n, {"", ""});
        for(int i = 0; i < n; i++)
            cin >> paths[i][0] >> paths[i][1];

        cout << ob.destCity(paths) << endl;
    }

    return 0;
}

/* Sample Input:
3
3
London NewYork
NewYork Lima
Lima SaoPaolo
3
B C
D B
C A
1
A Z

Sample Output:
SaoPaolo
A
Z

*/