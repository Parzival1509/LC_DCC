// LC DCC 2023/12/23
// 1496. Path Crossing
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> st;
        st.insert({0, 0});
        int x = 0, y = 0;

        for(char c: path) {
            if(c == 'N') {
                if(st.find({x, ++y}) == st.end())
                    st.insert({x, y});
                else return true;
            }
            else if(c == 'S') {
                if(st.find({x, --y}) == st.end())
                    st.insert({x, y});
                else return true;
            }
            else if(c == 'E') {
                if(st.find({++x, y}) == st.end())
                    st.insert({x, y});
                else return true;
            }
            else {
                if(st.find({--x, y}) == st.end())
                    st.insert({x, y});
                else return true;
            }
        }

        return false;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string path;
        cin >> path;
        if(ob.isPathCrossing(path)) cout << "true ";
        else cout << "false ";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
NES
NESWW

Sample Output:
false 
true 

*/