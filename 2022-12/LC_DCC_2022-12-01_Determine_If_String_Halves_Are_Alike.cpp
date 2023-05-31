// LC DCC 2022/12/01
// 1704. Determine if String Halves Are Alike
// Easy

#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();
bool cmp(pair<string, int> A, pair<string, int> B){
    if(A.first != B.first)
        return A.second < B.second;
    return B.first > A.first;
}

class Solution {
public:
    bool halvesAreAlike(string s) {
        int ct=0;
        for(int i=0; i<s.size()/2; i++)
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                ct++;
        for(int i=s.size()/2; i<s.size(); i++)
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                ct--;
        if(ct==0)
            return true;
        return false;
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<ob.halvesAreAlike(s)<<endl;
    }
    return 0;
}

/* Sample Input
2
book
textbook

Sample Output
1
0

*/