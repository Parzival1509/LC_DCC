// LC DCC 2023/01/21
// 93. Restore IP Addresses
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(string s, int n, int ind, int dots, string ip, vector<string>& ans) {
        // Base Condition
        if(ind == n && dots == 4) {
            ip.erase(ip.end()-1);
            ans.push_back(ip);
            return;
        }

        if(n-ind > (4-dots)*3) return;  // Size of remaining string is more than permissible digits
        if(n-ind < 4-dots) return;      // Size of remaining string is less than remaining no. of dots
        
        int num = 0;

        for(int i=ind; i<ind+3; i++) {
            num = num*10 + (s[i]-'0');
            if(num <= 255) {
                ip += s[i];
                dfs(s, n, i+1, dots+1, ip+'.', ans);
            }
            if(num == 0) break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string ip;
        dfs(s, s.size(), 0, 0, ip, ans);
        return ans;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        string s;
        cin>>s;
        vector<string> ans = ob.restoreIpAddresses(s);
        cout<<ans.size()<<endl;
        for(auto el: ans)
            cout<<el<<endl;
        cout<<endl;
    }
    return 0;
}

/* Sample Input
3
25525511135
0000
101023

Sample Output
2
255.255.11.135
255.255.111.35

1
0.0.0.0

5
1.0.10.23
1.0.102.3
10.1.0.23
10.10.2.3
101.0.2.3


*/