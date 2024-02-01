// LC DCC 2022/11/10
// 1047. Remove All Adjacent Duplicates In String
// Easy

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
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if((st.empty()) || (!st.empty() && st.top()!=s[i]))
                st.push(s[i]);
            else
                st.pop();                
        }
        s="";
        while(!st.empty()){
            s = st.top()+s;
            st.pop();
        }
        return s;
    }
};

int main(){
    Solution ob;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<ob.removeDuplicates(s)<<endl;
    }
    return 0;
}

/* Sample Input
2
abbaca
azxxzy

Sample Output
ca
ay

*/