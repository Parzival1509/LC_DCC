// LC DCC 2022/11/13
// 151. Reverse Words in a String
// Medium

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

class Solution {
public:
    string reverseWords(string s) {
        string tmp="", ans;
        int i=s.size()-1;
        while(i>=0) {
            if(s[i]!=' ')
                tmp = s[i]+tmp;
            else if(s[i]==' ' && i>0 && s[i-1]!=' ' && tmp.size()>0) {
                ans += tmp+" ";
                tmp = "";
            }
            i--;
        }
        if(tmp.size()>0)
            ans += tmp;
        if(ans[ans.size()-1]==' ')
            ans.pop_back();
        return ans;
    }
};

// class Solution {
// public:
//     string reverseWords(string s) {
//         string tmp="";
//         int i=s.size()-1, n=s.size();
//         while(i>=0) {
//             if(s[i]!=' ')
//                 tmp = s[i]+tmp;
//             else if(s[i]==' ' && i>0 && s[i-1]!=' ' && tmp.size()>0) {
//                 s += tmp+" ";
//                 tmp = "";
//             }
//             i--;
//         }
//         if(tmp.size()>0)
//             s += tmp;
//         s = s.substr(n, s.size()-n);
//         return s;
//     }
// };

// class Solution {
// public:
//     string reverseWords(string s) {
//         string tmp="", ans;
//         int i=s.size()-1, ct=0;
//         vector<int> ctv, indv;
//         while(i>=0) {
//             if(s[i]!=' ')
//                 ++ct;
//             else if(s[i]==' ' && i<s.size()-1 && s[i+1]!=' ') {
//                 indv.push_back(i+1);
//                 ctv.push_back(ct);
//                 ct=0;
//                 i--;
//             }
//         }
//         if(ct>0) {
//             indv.push_back(i+1);
//             ctv.push_back(ct);
//         }
//         for(int i=0; i<indv.size(); i++) {
//             ans += s.substr(indv[i], ctv[i]);
//         }
//         return ans;
//     }
// };

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        string s, ans;
        cin>>s;
        ans = ob.reverseWords(s);
        cout<<ans<<endl;
    }
    return 0;
}

/* Sample Input
3
the sky is blue
  hello world  
  a good   example
  
Sample Output
2
5

*/