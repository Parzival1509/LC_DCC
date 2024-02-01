// LC DCC 2023/01/22
// 131. Palindrome Partitioning
// Medium

#include<bits/stdc++.h>
using namespace std;

int start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

class Solution {
public:
    bool isPalindrome(string st, int start, int end) {
        while(start <= end)
            if(st[start++] != st[end--])
                return false;
        return true;
    }

    void helper(int index, string s, vector<string>& path, vector<vector<string>>& ans) {
        if(index == s.size()) {
            ans.push_back(path);
            return;
        }
        for(int i=index; i<s.size(); i++) {
            if(isPalindrome(s.substr(index, i-index+1), index, i)) {
                path.push_back(s.substr(index, i-index+1));
                helper(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(0, s, path, ans);
        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        vector<vector<string>> ans = ob.partition(s);
        for(auto el: ans) {
            for(auto ell: el)
                cout<<ell<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}

/* Sample Input
3
a
aab
aabb

Sample Output
a 

a a b 
aa b 

a a b b 
a a bb 
aa b b 
aa bb 


*/