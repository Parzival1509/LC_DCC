// LC DCC 2023/09/26
// 316. Remove Duplicate Letters
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);
        for(int i = 0; i < s.length(); i++)
            lastIndex[s[i] - 'a'] = i;
        
        vector<bool> seen(26, false);
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if(seen[curr]) continue;
            while(st.size() > 0 && st.top() > s[i] && i < lastIndex[st.top() - 'a']) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(s[i]);
            seen[curr] = true;
        }
        
        string ans = "";
        while (st.size() > 0) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s;
        cin >> s;
        cout << ob.removeDuplicateLetters(s) << endl;
    }

    return 0;
}

/* Sample Input:
2
bcabc
cbacdcbc

Sample Output:
abc
acdb

*/