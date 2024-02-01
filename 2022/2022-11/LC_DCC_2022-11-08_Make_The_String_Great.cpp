// LC DCC 2022/11/08
// 1544. Make The String Great
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
    string makeGood(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(!st.empty() && abs(st.top()-s[i])==32)
                st.pop();
            else
                st.push(s[i]);
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
        cout<<ob.makeGood(s)<<endl;
    }
    return 0;
}

/* Sample Input
2
leEeetcode
abBAcC

Sample Output
leetcode


*/