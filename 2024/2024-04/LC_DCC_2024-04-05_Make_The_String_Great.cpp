// LC DCC 2024/04/05
// 1544. Make The String Great
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
            if (!st.empty() && abs(st.top() - s[i]) == 32)
                st.pop();
            else st.push(s[i]);
        
        s = "";
        while (!st.empty()) {
            s = st.top() + s;
            st.pop();
        }

        return s;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.makeGood(s) << endl;
    }

    return 0;
}

/* Sample Input
3
s
leEeetcode
abBAcC

Sample Output
s
leetcode


*/