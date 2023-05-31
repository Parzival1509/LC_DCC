// LC DCC 2023/04/11
// 2390. Removing Stars From a String
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        for(auto ch: s) {
            if(ch != '*') ans += ch;
            else ans.pop_back();
        }
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
        cout<<ob.removeStars(s)<<endl;
    }
    return 0;
}

/* Sample Input:
2
leet**cod*e
erase*****

Sample Output:
lecoe


*/