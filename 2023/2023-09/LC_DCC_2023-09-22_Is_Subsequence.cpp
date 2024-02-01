// LC DCC 2023/09/22
// Is Subsequence
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sn = s.size(), tn = t.size();
        if(sn > tn) return false;

        int i = 0, j = 0;
        while(j < tn) {
            if(s[i] == t[j]) i++;
            if(i == sn) return true;
            j++;
        }
        
        return i == sn;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        string s, t;
        cin >> s >> t;
        
        if(ob.isSubsequence(s, t)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }

    return 0;
}

/* Sample Input:
2
abc ahbgdc
axc ahbgdc

Sample Output:
true 
false 

*/