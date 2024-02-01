// LC DCC 2023/04/12
// 71. Simplify Path
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        stack<string> st;
        
        for(int i=0; i<path.size(); i++) {
            if(path[i] == '/') continue;
            
            string tmp = "";
            while(i < path.size() && path[i] != '/') {
                tmp += path[i];
                i++;
            }

            if(tmp == ".") continue;
            else if(tmp == "..") {
                if(!st.empty()) st.pop();
            }
            else st.push(tmp);
        }

        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if(ans.size() == 0)
            return "/";
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        string s;
        cin>>s;
        cout<<ob.simplifyPath(s)<<endl;
    }
    return 0;
}

/* Sample Input:
4
/home/
/../
/home//foo/
/a/./b/../../c/

Sample Output:
/home
/
/home/foo
/c

*/