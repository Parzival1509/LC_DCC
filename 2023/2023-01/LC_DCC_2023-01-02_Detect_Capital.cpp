// LC DCC 2023/01/02
// 520. Detect Capital
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt1=0, cnt2=0;
        for(int i=0; i<word.size(); i++)
            if(word[i] >='A' && word[i]<='Z') cnt1++;
            else cnt2++;
       
        if(cnt1 == word.size()) return true;
        else if(cnt2==word.size()) return true;
        else if(cnt1==1 && isupper(word[0])) return true;
        return false;
    }
};

int main() {
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        string word;
        cin>>word;
        cout<<ob.detectCapitalUse(word)<<endl;
    }
    return 0;
}

/* Sample Input
3
USA
Parzival
FlAg

Sample Output
1
1
0

*/